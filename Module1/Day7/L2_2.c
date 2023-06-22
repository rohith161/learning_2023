#include "sensorInfo.h"
int UpdateEntry(SensorInfo *,int);

int main(){

    FILE* Log = fopen("data.csv", "r");
    int size = 0;
    SensorInfo* sensor = NULL;
    readFile(&sensor,Log,&size);
    //displaySensorInfo(sensor, size);
    UpdateEntry(sensor,size);
    //displaySensorInfo(sensor, size);
    free(sensor);
    fclose(Log);
    return 0;
}

int UpdateEntry(SensorInfo* ptr,int size){
    int entryno = 0 ;
    int flag = 0;
    printf("\nEnter the EntryNo to Upadte that EntryNo sensorInfo : ");
    scanf("%d",&entryno);
    for(int i=0; i<size; i++){
        if(ptr[i].EntryNo == entryno){
            printf("EntryNo found..\n");
            displaySensorInfo(&ptr[i]);
            printf("Enter the SensorNo : ");
            scanf("%s",ptr[i].SensorNo);
            printf("Enter the Temperature : ");
            scanf("%f",&ptr[i].Temperature);
            printf("Enter the Humidity : ");
            scanf("%d",&ptr[i].Humidity);
            printf("Enter the Light : ");
            scanf("%d",&ptr[i].Light);
            printf("Enter the Time : ");
            scanf("%s",&ptr[i].Time);
            displaySensorInfo(&ptr[i]);
            flag = 1;
        }
    }
    printf("%s",(flag == 1)?"Updation is Successful\n":"EntryNo not found\n");
    return flag;
}