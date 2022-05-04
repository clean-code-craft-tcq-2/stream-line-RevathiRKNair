#pragma once
void receiveData(float* currentReading, float* voltageReading, int noOfSamples);
float findMin(float* input, int streamSize);
float findMax(float* input, int streamSize);
float computeAvg(float* input, int streamSize);
float computeSMA(float *input, int winSize);
void minMaxValues(float* currentReading, float* voltageReading, int streamSize);
