#include<stdio.h>
void sumnAvg(int* arr,int size){
    int sum = 0, avg = 0;
    // sum of the Array elements
    for(int i=0; i<size; i++){
        sum += arr[i];
    }
    //Average of the sum of the array elements
    avg = sum/size;
    printf("The Sum and Average of the given Array \nSUM : %d\tAVERAGE : %d",sum,avg);
}
int main(){
    int arr[] = {12,84,20,36,64,56,72,10,45,90};
    int size = sizeof(arr)/sizeof(int);
    sumnAvg(arr,size);
    return 0;
}