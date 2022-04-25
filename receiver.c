#include "dataCollection.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readData(float* currentReading, float* voltageReading, int noOfSamples){
  for(int i = 0; i < noOfSamples; i++){
     scanf("%f", &currentReading[i]);
     scanf("%f", &voltageReading[i]);
     printf("%f, %f\n", currentReading[i], voltageReading[i]);
  }
}

float findMin(float* input, int streamSize){
  int min = input[0];
  for (int i=1; i<streamSize; i++){
    if(input[i]<min)
      min = input[i];
  }
  return min;
}

float findMax(float* input, int streamSize){
  int max = input[0];
  for (int i=1; i<streamSize; i++){
    if(input[i]>max)
      max = input[i];
  }
  return max;
}

void minMaxValues(float* currentReading, float* voltageReading, int streamSize) {
  float minI, maxI, minU, maxU;
  minI = findMin(currentReading, streamSize);
  maxI = findMax(currentReading, streamSize);
  minU = findMin(voltageReading, streamSize);
  maxU = findMax(voltageReading, streamSize);
  printf("min current: %f max current: %f min voltage: %f max voltage: %f\n", minI, maxI, minU, maxU);
}

int main()
{
    float Current[50], Voltage[50] = {0};
    readData(Current, Voltage, 50);  
    minMaxValues(Current, Voltage, 50);
}
