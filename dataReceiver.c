#include "dataReceiver.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void receiveData(float* currentReading, float* voltageReading, int noOfSamples){
  char ReadString[400];
  for(int i = 0; i < noOfSamples; i++){
    scanf("%50s", ReadString);
	  if(scanf("%50s", ReadString) == EOF) 
    {
       break;
    }
    scanf("%f", &currentReading[i]);
    scanf("%50s", ReadString); 
    scanf("%50s", ReadString);
    scanf("%50s", ReadString); 
    scanf("%50s", ReadString); 
    scanf("%50s", ReadString); 
    scanf("%50s", ReadString);
    scanf("%f", &voltageReading[i]);
	  printf("%.3f \t %.3f\n",currentReading[i],voltageReading[i]);
  }
}

float findMin(float* input, int streamSize){
  float min = input[0];
  for (int i=1; i<streamSize; i++){
    if(input[i]<min)
      min = input[i];
  }
  return min;
}

float findMax(float* input, int streamSize){
  float max = input[0];
  for (int i=1; i<streamSize; i++){
    if(input[i]>max)
      max = input[i];
  }
  return max;
}

float computeAvg(float* input, int streamSize)
{
    float avg = 0;
    float sum = 0;
    for(int i = 0; i < streamSize; i++)
    {
        sum = sum + input[i];
    }
    avg = sum/streamSize;
    return avg;
}

float computeSMA(float *input, int winSize) {
     float sum = 0, float movingAvg[50]={0};
     for (int i = 0; i < 50; i++) 
     {
         sum = sum + input[i];
         if (i >= winSize){
	     sum -= input[i-winSize];
	 }
	 if(i >= winSize - 1) {
            movingAvg[i-winSize] = sum / winSize;
	 }
     }
    return movingAvg;
}
	
void minMaxValues(float* currentReading, float* voltageReading, int streamSize) {
  float minI, maxI, minU, maxU;
  minI = findMin(currentReading, streamSize);
  maxI = findMax(currentReading, streamSize);
  minU = findMin(voltageReading, streamSize);
  maxU = findMax(voltageReading, streamSize);
  printf("min current: %f max current: %f min voltage: %f max voltage: %f\n", minI, maxI, minU, maxU);
}
