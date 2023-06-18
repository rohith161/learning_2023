#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void secondsCompute(char* str){
    printf("The total seconds for the given time %s\n",str);
    int num[3] = {0},seconds = 0;
    const char del = ':';
    char* token = strtok(str,&del);
    int i=0;
    while(token != NULL){
        num[i] = atoi(token); // conversion of string to integer
        i++;
        token = strtok(NULL,&del);
    }
    
    seconds = num[0] * 3600; // --Hours-- one hours has 60min * 60 sec = 3600
    seconds += num[1] * 60; // --Minutes-- one minutes has 60 sec 
    seconds += num[2]; // --Seconds--

    printf("Seconds : %d\n",seconds);
}

int main(){
    char str1[] = "10:12:50";
    char str2[] = "13:10:40";
    secondsCompute(str1);
    secondsCompute(str2);
    return 0;
}