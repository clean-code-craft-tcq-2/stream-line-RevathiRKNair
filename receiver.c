#include "dataCollection.h"

void readData(float* temperature, float* stateOfCharge, float* chargeRate, int noOfSamples){
  for(int i = 0; i < noOfSamples; i++){
     scanf("%f", &temperature[i]);
     scanf("%f", &stateOfCharge[i]);
     scanf("%f", &chargeRate[i]);
  }
}
