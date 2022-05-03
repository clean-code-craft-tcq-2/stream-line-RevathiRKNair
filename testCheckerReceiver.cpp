#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "dataReceiver.h"
#include <string.h>
#include <stdio.h>

TEST_CASE("Test for finding max and min value") 
{
  float current[5]= {1.2, 6.7, 8.4, 7.8, 5.6};
  float max = findMax(current, 5);
  float min = findMin(current, 5);
  float avg = computeAvg(current, 5);
  REQUIRE(max == 8.4f);
  REQUIRE(min == 1.2f);
  REQUIRE(Avg == 5.94f);
}

TEST_CASE("Test for Checking wether read of data from console input") 
{
  float current[1] = {0};
  float voltage[1] = {0};
  float current_ref[1] = {29.0};
  float voltage_ref[1] = {2.6};
  printf(" Current: %.2f , Voltage: %.2f ", current_ref[0],  voltage_ref[0]);
  //copy paste the following line on the console to perform test:
  receiveData(current, voltage, 1);
  REQUIRE(current[0] - current_ref[0] <= 0.001);
  REQUIRE(voltage[0] - voltage_ref[0] <= 0.001);
}


