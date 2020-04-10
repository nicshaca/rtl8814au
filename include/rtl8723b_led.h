. Finally the
     * resulting String is passed to {@link Long#parseLong(String, int)}} with
     * the specified radix.
     *
     * @param radix
     *            the radix used to translate the token into a {@code long}
     *            value.
     * @return the next token as a {@code long}.
     * @throws IllegalStateException
     *             if this {@code Scanner} has been closed.
     * @throws NoSuchElementException
     *             if input has been exhausted.
     * @throws InputMismatchException
     *             if the next token can not be translated into a valid
     *             {@code long} value.
     */
    @SuppressWarnings("boxing")
    public long nextLong(int radix) {
        checkOpen();
        Object obj = cachedNextValue;
        cachedNextValue = null;
        if (obj instanceof Long) {
            findStartIndex = cachedNextIndex;
            return (Long) obj;
        }
        Pattern integerPattern = getIntegerPattern(radix);
        String intString = next(integerPattern);
        intString = removeLocaleInfo(intString, int.class);
        long longValue = 0;
        try {
            longValue = Long.parseLong(intString, radix);
        } catch (NumberFormatException e) {
            matchSuccessful = false;
            recoverPreviousStatus();
            throw new InputMismatchException();
        }
        return longValue;
    }

    /**
     * Returns the next token as a {@code short} in the current radix.
     * This method may block for more input.
     *
     * @throws IllegalStateEx