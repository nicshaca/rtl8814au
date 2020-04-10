;
            if (mSessionEndDuringMerge) {
                // Set some local variables that will send out a notification about a
                // previously buried termination callback for our primary session now that
                // we know that this is not due to the conference call merging successfully.
                if (DBG) {
                    log("notifySessionTerminatedDuringMerge ::reporting terminate during merge");
                }
                notifyFailure = true;
                notifyFailureReasonInfo = mSessionEndDuringMergeReasonInfo;
            }

            mSessionEndDuringMerge = false;
            mSessionEndDuringMergeReasonInfo = null;
        }

        if (listener != null && notifyFailure) {
            try {
                processCallTerminated(notifyFailureReasonInfo);
            } catch (Throwable t) {
                loge("notifySessionTerminatedDuringMerge :: ", t);
            }
        }
    }

    /**
     * We received a callback from ImsCallSession that a merge failed. Clean up all
     * internal state to represent this state change.
     *
     * @param reasonInfo The {@link ImsReasonInfo} why the merge failed.
     */
    private void processMergeFailed(ImsReasonInfo reasonInfo) {
        if (VDBG) {
            String reasonString = reasonInfo != null ? reasonInfo.toString() : "null";
            logv("processMergeFailed :: reason=" + reasonString);
        }

        // Ensure any terminations are surfaced from this session.
        notifySessionTerminatedDuringMerge();

        // Ensure any terminations are surface from the other session.
        if (isMergeHost()) {
            mMergePeer.notifySessionTerminatedDuringMerge();
        } else if (isMergePeer()) {
            mMergeHost.notifySessionTerminatedDuringMerge();
        }

        ImsCall.Listener listener;
        synchronized(ImsCall.this) {
            listener = mListener;
            if (mTransientConferenceSession != null) {
                // Clean up any work that we performed on the transient session.
                mTransientConferenceSession.setListener(null);
                mTransientConferenceSession = null;
            }

            mSessionEndDuringMerge = false;
            mSessionEndDuringMergeReasonInfo = null;
            mUpdateRequest = UPDATE_NONE;

            // Ensure the call being conferenced into the conference has isMerged = false.
            if (isMergeHost()) {
                mMergePeer.setIsMerged(false);
            } else {
                setIsMerged(false);
            }
            // Unlink the two calls since they are no longer being involved in an attempted merge.
            clearMergePeer();
        }
        if (listener != null) {
            try {
                listener.onCallMergeFailed(ImsCall.this, reasonInfo);
            } catch (Throwable t) {
                loge("processMergeFailed :: ", t);
            }
        }
        return;
    }

    private void notifyError(int reason, int statusCode, String message) {
    }

    private void throwImsException(Throwable t, int code) throws ImsException {
        if (t instanceof ImsException) {
            throw (ImsException) t;
        } else {
            throw new ImsException(String.valueOf(code), t, code);
        }
    }

    private void log(String s) {
        Rlog.d(TAG, s);
    }

    /**
     * Logs the specified message, as well as the current instance of {@link ImsCall}.
     *
     * @param s The message to log.
     */
    private void logv(String s) {
        StringBuilder sb = new StringBuilder();
        sb.append(s);
        sb.append(" imsCall=");
        sb.append(ImsCall.this);
        Rlog.v(TAG, sb.toString());
    }

    private void loge(String s) {
        Rlog.e(TAG, s);
    }

    private void loge(String s, Throwable t) {
        Rlog.e(TAG, s, t);
    }

    private class ImsCallSessionListenerProxy extends ImsCallSession.Listener {
        @Override
        public void callSessionProgressing(ImsCallSession session, ImsStreamMediaProfile profile) {
            if (isTransientConferenceSession(session)) {
                log("callSessionProgressing :: not supported for transient conference session=" +
                        session);
                return;
            }

            if (VDBG) {
                logv("callSessionProgressing :: profile=" + profile);
            }

            ImsCall.Listener listener;

            synchronized(ImsCall.this) {
                listener = mListener;
                mCallProfile.mMediaProfile.copyFrom(profile);
            }

            if (listener != null) {
                try {
                    listener.onCallProgressing(ImsCall.this);
                } catch (Throwable t) {
                    loge("callSessionProgressing :: ", t);
                }
            }
        }

        @Override
        public void callSessionStarted(ImsCallSession session, ImsCallProfile profile) {
            if (VDBG) {
                logv("callSessionStarted :: profile=" + profile);
            }

            // Check if there is an ongoing conference merge which has completed.  If there is
            // we can process the merge completion now.
            if (hasCallSessionMergeCompleted()) {
                processMergeComplete();
                return;
            }

            ImsCall.Listener listener;

            synchronized(ImsCall.this) {
                listener = mListener;
                mCallProfile = profile;
            }

            if (listener != null) {
                try {
                    listener.onCallStarted(ImsCall.this);
                } catch (Throwable t) {
                    loge("callSessionStarted :: ", t);
                }
            }
        }

        @Override
        public void callSessionStartFailed(ImsCallSession session, ImsReasonInfo reasonInfo) {
            if (isTransientConferenceSession(session)) {
                log("callSessionStartFailed :: not supported for transient conference session=" +
                        session);
                return;
            }

            if (VDBG) {
                logv("callSessionStartFailed :: reasonInfo=" + reasonInfo);
            }

            ImsCall.Listener listener;

            synchronized(ImsCall.this) {
                listener = mListener;
                mLastReasonInfo = reasonInfo;
            }

            if (listener != null) {
                try {
                    listener.onCallStartFailed(ImsCall.this, reasonInfo);
                } catch (Throwable t) {
                    loge("callSessionStarted :: ", t);
                }
            }
        }

        @Override
        public void callSessionTerminated(ImsCallSession session, ImsReasonInfo reasonInfo) {
            if (mSession != session) {
                log("callSessionTerminated :: not supported for conference session=" + session);
                return;
            }

            // If session has terminated, it is no longer pending merge.
            setCallSessionMergePending(false);

            // Check if there is an ongoing conference merge which has completed.  If there is
            // we can process the merge completion now.
            if (hasCallSessionMergeCompleted()) {
                processMergeComplete();
                return;
            }

            if (VDBG) {
                logv("callSessionTerminated :: reasonInfo=" + reasonInfo);
            }

            processCallTerminated(reasonInfo);
        }

        @Override
        public void callSessionHeld(ImsCallSession session, ImsCallProfile profile) {
            if (isTransientConferenceSession(session)) {
                log("callSessionHeld :: not supported for transient conference session=" + session);
                return;
            }

            if (VDBG) {
                logv("callSessionHeld :: profile=" + profile);
            }

            ImsCall.Listener listener;

            synchronized(ImsCall.this) {
                // If the session was held, it is no longer pending a merge -- this means it could
                // not be merged into the conference and was held instead.
                setCallSessionMergePending(false);

                mCallProfile = profile;

                if (mUpdateRequest == UPDATE_HOLD_MERGE) {
                    mergeInternal();
                    return;
                }

                // Check if there is an ongoing conference merge which has completed.  If there is
                // we can process the merge completion now.
                if (hasCallSessionMergeCompleted()) {
                    processMergeComplete();
                }

                mUpdateRequest = UPDATE_NONE;
                listener = mListener;
            }

            if (listener != null) {
                try {
                    listener.onCallHeld(ImsCall.this);
                } catch (Throwable t) {
                    loge("callSessionHeld :: ", t);
                }
            }
        }

        @Override
        public void callSessionHoldFailed(ImsCallSession session, ImsReasonInfo reasonInfo) {
            if (isTransientConferenceSession(session)) {
                log("callSessionHoldFailed :: not supported for transient conference session=" +
                        session);
                return;
            }

            if (VDBG) {
                logv("callSessionHoldFailed :: reasonInfo=" + reasonInfo);
            }

            boolean isHoldForMerge = false;
            ImsCall.Listener listener;

            synchronized(ImsCall.this) {
                if (mUpdateRequest == UPDATE_HOLD_MERGE) {
                    isHoldForMerge = true;
                }

                mUpdateRequest = UPDATE_NONE;
                listener = mListener;
            }

            if (isHoldForMerge) {
                // Is hold for merge implemented/supported? If so we need to take a close look
                // at this workflow to make sure that we handle the case where
                // callSessionMergeFailed() does the right thing because we have not actually
                // started the merge yet.
                callSessionMergeFailed(session, reasonInfo);
                return;
            }

            if (listener != null) {
                try {
                    listener.onCallHoldFailed(ImsCall.this, reasonInfo);
                } catch (Throwable t) {
                    loge("callSessionHoldFailed :: ", t);
                }
            }
        }

        @Override
        public void callSessionHoldReceived(ImsCallSession session, ImsCallProfile profile) {
            if (isTransientConferenceSession(session)) {
                log("callSessionHoldReceived :: not supported for transient conference session=" +
                        session);
                return;
            }

            if (VDBG) {
                logv("callSessionHoldReceived :: profile=" + profile);
            }

            ImsCall.Listener listener;

            synchronized(ImsCall.this) {
                listener = mListener;
                mCallProfile = profile;
            }

            if (listener != null) {
                try {
                    listener.onCallHoldReceived(ImsCall.this);
                } catch (Throwable t) {
                    loge("callSessionHoldReceived :: ", t);
                }
            }
        }

        @Override
        public void callSessionResumed(ImsCallSession session, ImsCallProfile profile) {
            if (isTransientConferenceSession(session)) {
                log("callSessionResumed :: not supported for transient conference session=" +
                        session);
                return;
            }

            if (VDBG) {
                logv("callSessionResumed :: profile=" + profile);
            }

            ImsCall.Listener listener;

            synchronized(ImsCall.this) {
                listener = mListener;
                mCallProfile = profile;
                mUpdateRequest = UPDATE_NONE;
                mHold = false;
            }

            if (listener != null) {
                try {
                    listener.onCall