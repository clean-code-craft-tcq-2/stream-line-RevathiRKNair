#include "dataCollection.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readData(float* temperature, float* stateOfCharge, float* chargeRate, int noOfSamples){
  for(int i = 0; i < noOfSamples; i++){
     scanf("%f", &temperature[i]);
     scanf("%f", &stateOfCharge[i]);
     scanf("%f", &chargeRate[i]);
     printf("%f, %f, %f\n", temperature[i], stateOfCharge[i], chargeRate[i]);
  }
}

int main()
{
    float Temperature[50],StateOfCharge[50],ChargeRate[50] = {0};
    readData(Temperature, StateOfCharge, ChargeRate, 50);   
}
