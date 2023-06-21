#include <stdio.h>
#include <stdlib.h>

typedef struct Time{
    int hour;
    int minutes;
    int seconds;
}Time;


// function to read time periods
void readTime(Time* ptr,char* time){
    sscanf(time,"%d:%d:%d",&ptr->hour,&ptr->minutes,&ptr->seconds);
}

// function to calculate period difference
Time diffInPeriod(Time* T1, Time* T2){
    int seconds1 = (T1->hour * 3600) + (T1->minutes * 60) + T1->seconds;
    int seconds2 = (T2->hour * 3600) + (T2->minutes * 60) + T2->seconds;
    int diffseconds = abs(seconds1 - seconds2);
    Time diffPeriod;
    diffPeriod.hour = (diffseconds / 3600);
    diffPeriod.minutes = (diffseconds % 3600) / 60;
    diffPeriod.seconds = (diffseconds % 3600) % 60;
    return diffPeriod;
}

int main(){
    Time T1,T2;
    char time1[] = "03:12:56";
    char time2[] = "10:07:37";
    readTime(&T1,time1);
    readTime(&T2,time2);
    Time diff = diffInPeriod(&T1,&T2);
    printf("Time period Difference between %s and %s\nDifference --> %d:%d:%d",time1,time2,diff.hour,diff.minutes,diff.seconds);
    return 0;
}