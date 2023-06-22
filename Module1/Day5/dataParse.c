#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SensorInfo
{
    char Id[3];
    float Temperature;
    int humidity;
    int Light_Intensity;
} SensorInfo;

//Function to assign the values to the sensor strucure fields
void initSensorInfo(SensorInfo* ptr,char* id,float T,int H,int L){
    strcpy(ptr->Id,id);
    ptr->Temperature = T;
    ptr->humidity = H;
    ptr->Light_Intensity = L;
}
//Function to read the sensor info to the their parameters
void SensorPopulate(SensorInfo* sensor,int size,const char* str){
    for (int i = 0; i < size; i++) {
        char Id[3];
        float T;
        int H;
        int L;
        sscanf(str,"%2s-T:%f-H:%d-L:%d",Id,&T,&H,&L);
        initSensorInfo(&sensor[i],Id,T,H,L);
   }
}
//Function to display the Sendor Info accoding to their fields
void displaySensorInfo(SensorInfo* sensor,int size){
    for (int i = 0; i < size; i++) {
        printf("Sensor Info:\n---------------\n");
        printf("Sensor ID: %s\nTemperature: %.1f C\nHumidity: %d\nLight Intensity: %d%%\n", sensor[i].Id, sensor[i].Temperature, sensor[i].humidity, sensor[i].Light_Intensity);
        printf("---------------\n");
    }
}
int main() {
    char str[] = "S1-T:36.5-H:100-L:50";
    int size = 1;

    SensorInfo* sensor = calloc(size, sizeof(SensorInfo));
    if (sensor == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    SensorPopulate(sensor,size,str);
    displaySensorInfo(sensor,size);
    free(sensor);

    return 0;
}
