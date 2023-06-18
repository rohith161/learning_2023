#include <stdio.h>

void diffEvenOddIndex(int* arr,int size){
    int sumEvenInd = 0,sumOddInd = 0;
    for(int i=0; i<size; i++){
        //To check if the array element Index is even or odd
        if(i%2 == 0){
            sumEvenInd += arr[i];
        }
        else{
            sumOddInd += arr[i];
        }
    }
    printf("The difference between sum of EVEN and ODD Indexed elements of Array\nSum of EVEN Indexed Elements of Array : %d\nSum of ODD Indexed Elements of Array  : %d",sumEvenInd,sumOddInd);

}

int main(){
    int arr[] = {64,84,21,36,17,90,77,10,48,55};
    int size = sizeof(arr)/sizeof(int);
    diffEvenOddIndex(arr,size);
    return 0;
}