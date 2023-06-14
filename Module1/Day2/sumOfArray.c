#include<stdio.h>

int main(){
    // array of length 5
    int a[5] = {10,20,30,40,50},sum=0;

    // i is increamented by +2 for every iteration
    for(int i=0; i<sizeof(a)/sizeof(int); i+=2){
        sum += a[i];
    }

    //final sum of the array alternate elements
    printf("The sum of the array alternate elements : %d\n",sum);
    return 0;
}