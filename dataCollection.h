#pragma once
#include <stdio.h>
typedef struct Charger
{
	float current;
	float voltage;
}Charger;

void convertSensorDataToJson (Charger sensor_data, char *jsonData);
void streamData (char *dataStream, FILE *endPoint);
void postProcessingSensorData (Charger sensor_data, char *jsonData);