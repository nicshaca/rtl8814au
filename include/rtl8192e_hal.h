/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package android.database;

/**
 * This exception is thrown when a CursorWindow couldn't be allocated,
 * most probably due to memory not being available.
 *
 * @hide
 */
public class CursorWindowAllocationException extends RuntimeException {
    public CursorWindowAllocationException(String description) {
        super(description);
    }
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package android.bordeaux.services;

import android.bordeaux.learning.MulticlassPA;
import android.os.IBinder;

import java.util.List;
import java.util.ArrayList;

public class Learning_MulticlassPA extends ILearning_MulticlassPA.Stub
        implements IBordeauxLearner {
    private MulticlassPA mMulticlassPA_learner;
    private ModelChangeCallback modelChangeCallback = null;

    class IntFloatArray {
        int[] indexArray;
        float[] floatArray;
    };

    private IntFloatArray splitIntFloatArray(List<IntFloat> sample) {
        IntFloatArray splited = new IntFloatArray();
        ArrayList<IntFloat> s = (ArrayList<IntFloat>)sample;
        splited.indexArray = new int[s.size()];
        splited.floatArray = new float[s.size()];
        for (int i = 0; i < s.size(); i++) {
            splited.indexArray[i] = s.get(i).index;
            splited.floatArray[i] = s.get(i).value;
        }
        return splited;
    }

    public Learning_MulticlassPA() {
        mMulticlassPA_learner = new MulticlassPA(2, 2, 0.001f);
    }

    // Beginning of the IBordeauxLearner Interface implementation
    public byte [] getModel() {
        return null;
    }

    public boolean setModel(final byte [] modelData) {
        return false;
    }

    public IBinder getBinder() {
        return this;
    }

    public void setModelChangeCallback(ModelChangeCallback callback) {
        modelChangeCallback = callback;
    }
    // End of IBordeauxLearner Interface implemenation

    // This implementation, combines training and prediction in one step.
    // The return value is the prediction value for the supplied sample. It
    // also update the model with the current sample.
    public void TrainOneSample(List<IntFloat> sample, int target) {
        IntFloatArray splited = splitIntFloatArray(sample);
        mMulticlassPA_learner.sparseTrainOneExample(splited.indexArray,
                                                    splited.floatArray,
                                                    target);
        if (modelChangeCallback != null) {
            modelChangeCallback.modelChanged(this);
        }
    }

    public int Classify(List<IntFloat> sample) {
        IntFloatArray splited = splitIntFloatArray(sample);
        int prediction = mMulticlassPA_learner.sparseGetClass(splited.indexArray,
                                                              splited.floatArray);
        return prediction;
    }

}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               /*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package android.bordeaux.services;

import android.bordeaux.learning.StochasticLinearRanker;
import android.bordeaux.services.IBordeauxLearner.ModelChangeCallback;
import android.os.IBinder;
import android.util.Log;
import java.util.List;
import java.util.ArrayList;
import java.io.*;
import java.lang.ClassNotFoundException;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.io.ByteArrayOutputStream;
import java.util.HashMap;
import java.util.Map;

public class Learning_StochasticLinearRanker extends ILearning_StochasticLinearRanker.Stub
        implements IBordeauxLearner {

    private final String TAG = "ILearning_StochasticLinearRanker";
    private StochasticLinearRankerWithPrior mLearningSlRanker = null;
    private ModelChangeCallback modelChangeCallback = null;

    public Learning_StochasticLinearRanker(){
    }

    public void ResetRanker(){
        if (mLearningSlRanker == null)
            mLearningSlRanker = new StochasticLinearRankerWithPrior();
        mLearningSlRanker.resetRanker();
    }

    public boolean UpdateClassifier(List<StringFloat> sample_1, List<StringFloat> sample_2){
        ArrayList<StringFloat> temp_1 = (ArrayList<StringFloat>)sample_1;
        String[] keys_1 = new String[temp_1.size()];
        float[] values_1 = new float[temp_1.size()];
        for (int i = 0; i < temp_1.size(); i++){
            keys_1[i] = temp_1.get(i).key;
            values_1[i] = temp_1.get(i).value;
        }
        ArrayList<StringFloat> temp_2 = (ArrayList<StringFloat>)sample_2;
        String[] keys_2 = new String[temp_2.size()];
        float[] values_2 = new float[temp_2.size()];
        for (int i = 0; i < temp_2.size(); i++){
            keys_2[i] = temp_2.get(i).key;
            values_2[i] = temp_2.get(i).value;
        }
        if (mLearningSlRanker == null)
            mLearningSlRanker = new StochasticLinearRankerWithPrior();
        boolean res = mLearningSlRanker.updateClassifier(keys_1,values_1,keys_2,values_2);
        if (res && modelChangeCallback != null) {
            modelChangeCallback.modelChanged(this);
        }
        return res;
    }

    public float ScoreSample(List<StringFloat> sample) {
        ArrayList<StringFloat> temp = (ArrayList<StringFloat>)sample;
        String[] keys = new String[temp.size()];
        float[] values = new float[temp.size()];
        for (int i = 0; i < temp.size(); i++){
            keys[i] = temp.get(i).key;
            values[i] = temp.get(i).value;
        }
        if (mLearningSlRanker == null)
            mLearningSlRanker = new StochasticLinearRankerWithPrior();
        return mLearningSlRanker.scoreSample(keys,values);
    }

    public boolean SetModelPriorWeight(List<StringFloat> sample) {
        ArrayList<StringFloat> temp = (ArrayList<StringFloat>)sample;
        HashMap<String, Float> weights = new HashMap<String, Float>();
        for (int i = 0; i < temp.size(); i++)
            weights.put(temp.get(i).key, temp.get(i).value);
        if (mLearningSlRanker == null)
            mLearningSlRanker = new StochasticLinearRankerWithPrior();
        return mLearningSlRanker.setModelPriorWeights(weights);
    }

    public boolean SetModelParameter(String key, String value) {
        if (mLearningSlRanker == null)
            mLearningSlRanker = new StochasticLinearRankerWithPrior();
        return mLearningSlRanker.setModelParameter(key,value);
    }

    // Beginning of the IBordeauxLearner Interface implementation
    public byte [] getModel() {
        if (mLearningSlRanker == null)
            mLearningSlRanker = new StochasticLinearRankerWithPrior();
        StochasticLinearRankerWithPrior.Model model = mLearningSlRanker.getModel();
        try {
            ByteArrayOutputStream byteStream = new ByteArrayOutputStream();
            ObjectOutputStream objStream = new ObjectOutputStream(byteStream);
            objStream.writeObject(model);
            //return byteStream.toByteArray();
            byte[] bytes = byteStream.toByteArray();
            return bytes;
        } catch (IOException e) {
            throw new RuntimeException("Can't get model");
        }
    }

    public boolean setModel(final byte [] modelData) {
        try {
            ByteArrayInputStream input = new ByteArrayInputStream(modelData);
            ObjectInputStream objStream = new ObjectInputStream(input);
            StochasticLinearRankerWithPrior.Model model =
     