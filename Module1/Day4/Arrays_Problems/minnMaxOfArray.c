#include <stdio.h>

void minnMaxOfArray(int* arr, int size){
    int min =0, max=0;
    for(int i=0; i<size; i++){
        int temp = arr[i];
        /* for intial stage since the min would be initialzed to zero
         that would be min value so min intialze with one of the array element */
        if(i==0){
            min = temp;
            continue;
        }
        // for checking the min value
        if(temp < min){
            min = temp;
        }
        // for checking the max value
        if(temp > max){
            max = temp;
        }
    }
    printf("The minimum and maximum of the fiven Array elements\nMIN : %d\tMAX : %d",min,max);
}

int main(){
    int arr[] = {64,84,20,36,12,90,72,10,45,56};
    int size = sizeof(arr)/sizeof(int);
    minnMaxOfArray(arr,size);
    return 0;
}