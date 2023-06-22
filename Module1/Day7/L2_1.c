#include "sensorInfo.h"

void sortTempDes(SensorInfo* ,int );
void swap(SensorInfo* ,SensorInfo* );

int main(){

    FILE* Log = fopen("data.csv", "r");
    int size = 0;
    SensorInfo* sensor = NULL;
    readFile(&sensor,Log,&size);
    displayAllSensorInfo(sensor, size);
    sortTempDes(sensor,size);
    displayAllSensorInfo(sensor, size);
    free(sensor);
    fclose(Log);
    return 0;
}

void sortTempDes(SensorInfo* ptr,int size){
    for(int i=0; i<size-1; i++){
        for(int j=i; j<size-1-i; j++){
            if(ptr[j].Temperature < ptr[j+1].Temperature){
                swap(&ptr[j],&ptr[j+1]);
            }
        }
    }
}

void swap(SensorInfo* ptr1,SensorInfo* ptr2){
    SensorInfo temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}