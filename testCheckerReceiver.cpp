
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "dataCollection.h"
#include <string.h>
#include <stdio.h>

TEST_CASE("Test to check Receiver") 
{ 
   BatteryChargingParameters ReceivedData[STREAM_SIZE], ExpectedData[STREAM_SIZE], Max, Min,Avg,MovingAvg[STREAM_SIZE];
   ReadDataFromConsole(ReceivedData);
   float Temperature_loc, StateOfCharge_loc;
    
   FILE * file= fopen("./batteryParameters.txt","r");                                                                  
   for(int i = 0 ; i < STREAM_SIZE; i++)
   {
     if (file!=NULL) 
     {
        for(int i=0;fscanf(file, "%f\t%f\n", &Temperature_loc,&StateOfCharge_loc)!=EOF ;i++)
        {
            ExpectedData[i].temperature = Temperature_loc;
            ExpectedData[i].stateOfCharge = StateOfCharge_loc;
        }
     }
       
     REQUIRE( (ReceivedData[i].temperature - ExpectedData[i].temperature) <= 0.001);
     REQUIRE( (ReceivedData[i].stateOfCharge - ExpectedData[i].stateOfCharge) <= 0.001);
   }
   fclose(file);
    Min= ComputeMinBMS_Data(ReceivedData);
    Max = ComputeMaxBMS_Data(ReceivedData);
    Avg = ComputeAvgBMS_Data(ReceivedData);
    
    ComputeMovingAvgBMS_Data(ReceivedData,MovingAvg,5);
   
    REQUIRE( abs(Min.temperature - 1.030 ) <=0.001);
    REQUIRE( abs(Max.temperature - 47.960 ) <=0.001);
    REQUIRE( abs(Avg.temperature - 24.587 ) <=0.001);
    REQUIRE( abs(Min.stateOfCharge - 3.910 ) <=0.001);
    REQUIRE( abs(Max.stateOfCharge - 78.830 ) <=0.001);
    REQUIRE( abs(Avg.stateOfCharge - 39.499 ) <=0.001);
    REQUIRE( abs(MovingAvg[0].temperature - 22.224 ) <=0.001);
    REQUIRE( abs(MovingAvg[0].stateOfCharge - 28.268 ) <=0.001);
    REQUIRE( abs(MovingAvg[44].temperature - 22.292 ) <=0.001);
    REQUIRE( abs(MovingAvg[44].stateOfCharge - 44.676 ) <=0.001);
    printf(" From the received data, The Maximum, Minimum and Average value of temperature is %.2f %.2f %.2f respectively and Maximum, Minimum and Average value of state of charge is %.2f %.2f %.2f respectively\n",Max.temperature,Min.temperature,Avg.temperature,Max.stateOfCharge,Min.stateOfCharge,Avg.stateOfCharge);

}
