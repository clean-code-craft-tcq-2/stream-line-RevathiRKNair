#include "dataCollection.h"
#define DATA_SIZE	50

float currentReading [DATA_SIZE] = {29.0,27.0,25.0,22.0,21.0,20.0,12.0,8.0,13.0,14.0,
								 11.0,4.0,3.0,26.0,47.0,9.0,10.0,15.0,17.0,18.0,
								 16.0,22.0,6.0,24.0,28.0,9.0,2.0,5.0,22.0,19.0,
				                                 23.0,11.0,18.0,1.0,14.0,15.0,14.0,20.0,21.0,7.0,
				    				 19.0,10.0,16.0,11.0,8.0,21.0,5.0,8.0,10.0,2.0};
										 
float voltageReading [DATA_SIZE] = {2.6,1.6,3.6,4.6,5.6,6.6,7.6,8.6,9.6,3.1,
									 4.4,4.1,1.4,2.4,5.4,6.4,7.4,8.4,9.4,1.7,
									 1.9,2.9,3.9,4.9,5.9,6.5,4.2,3.1,8.0,7.1,
				                                         2.5,3.0,2.1,6.4,7.0,7.5,6.9,2.3,1.5,1.0,
				                                         0.5,1.5,2.5,3.5,6.5,7.0,7.6,8.0,8.5,9.0};


int main ()
{
	char dataStream[64];
	Charger sensor_data;
	FILE *endPoint = stdout;
	
	for (int readIndex = 0; readIndex < DATA_SIZE; readIndex ++)
	{
		sensor_data.current = currentReading[readIndex];
		sensor_data.voltage = voltageReading[readIndex];
		postProcessingSensorData (sensor_data, dataStream);
		streamData(dataStream, endPoint);
	}
	
	return 0;
}
												
