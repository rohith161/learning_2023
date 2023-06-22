#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SensorInfo
{
    int EntryNo;
    char SensorNo[3];
    float Temperature;
    int Humidity;
    int Light;
    char Time[9];
} SensorInfo;

// function to initialize the Sensor parameter 
void initSensor(SensorInfo* ptr, const char* str)
{
    sscanf(str, "%d,%2s,%f,%d,%d,%8s", &ptr->EntryNo, ptr->SensorNo, &ptr->Temperature, &ptr->Humidity, &ptr->Light, ptr->Time);
}
// Function to Diaplay the sendorInfo array of structure
void displayAllSensorInfo(SensorInfo* ptr, int size)
{
    printf("Sensor Info:\n---------------\n");
    for (int i = 0; i < size; i++) {
        printf("\nEntryNo: %d\nSensorNo: %s\nTemperature: %.1f\nHumidity: %d\nLight: %d\nTime: %s\n", ptr[i].EntryNo, ptr[i].SensorNo, ptr[i].Temperature, ptr[i].Humidity, ptr[i].Light, ptr[i].Time);
        printf("---------------\n");
    }
}
void displaySensorInfo(SensorInfo* ptr)
{
    printf("Sensor Info:\n---------------\n");
    
        printf("\nEntryNo: %d\nSensorNo: %s\nTemperature: %.1f\nHumidity: %d\nLight: %d\nTime: %s\n", ptr->EntryNo, ptr->SensorNo, ptr->Temperature, ptr->Humidity, ptr->Light, ptr->Time);
        printf("---------------\n");
}
//functiojn to read the the sensor parameters in data.csv
int readFile(SensorInfo** sensor,FILE* Log,int* size){
    char buffer[1024];
    int firstLine = 1;
    //to get each line from the file for iteration
    while (fgets(buffer, sizeof(buffer), Log) != NULL) {
        if (firstLine) {
            firstLine = 0;
            continue;
        }
        // to extent the memmoey size of the sensor array structure for evry new line of file
        *sensor = realloc(*sensor, (*size + 1) * sizeof(SensorInfo));
        if (sensor == NULL) {
            printf("Memory reallocation failed\n");
            return 1;
        }
        // to store the evry line of senor parameters
        initSensor(&((*sensor)[*size]), buffer);
        (*size) += 1;
    }
    return 0;
}