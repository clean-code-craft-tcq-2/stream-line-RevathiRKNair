#pragma once
void receiveData(float* currentReading, float* voltageReading, int noOfSamples);
float findMin(float* input, int streamSize);
float findMax(float* input, int streamSize);
float ComputeAvg(float* input, int streamSize);
void minMaxValues(float* currentReading, float* voltageReading, int streamSize);
