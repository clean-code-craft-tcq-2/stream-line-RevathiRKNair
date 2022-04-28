#include "dataReceiver.h"

int main()
{
    float Current[50], Voltage[50] = {0};
    receiveData(Current, Voltage, 50);  
    minMaxValues(Current, Voltage, 50);
    return 0;
}
