#include "dataCollection.h"

void convertSensorDataToJson (Charger sensor_data, char *jsonData)
{
	sprintf (jsonData, "{\"Current\": %.1f, \"Voltage\": %.1f}", sensor_data.current, sensor_data.voltage);
	return;
}

void streamData (char *dataStream, FILE *endPoint)
{
	fprintf (endPoint,"%s\n", dataStream);
	return;
}

void postProcessingSensorData (Charger sensor_data, char *jsonData)
{
	convertSensorDataToJson(sensor_data, jsonData);
	return;
}