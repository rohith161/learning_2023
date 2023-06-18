#include <stdio.h>
void printArray(int* arr,int size){
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
}
 void reverseArray(int* arr,int size){
    printf("Array elements Before reverse\n");
    printArray(arr,size);

    // reverse od array elemets
    for(int i=0; i<size/2; i++){
        int temp = arr[(size-1)-i];
        arr[(size-1)-i] = arr[i];
        arr[i] = temp;
    }
    printf("\n\nArray elements After reverse\n");
    printArray(arr,size);
 }
int main(){
    int arr[] = {64,84,20,36,12,90,72,10,45,56};
    int size = sizeof(arr)/sizeof(int);
    reverseArray(arr,size);
    return 0;
}