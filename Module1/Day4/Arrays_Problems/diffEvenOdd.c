#include <stdio.h>
void diffEvenOdd(int* arr,int size){
    int sumEven = 0,sumOdd = 0;
    for(int i=0; i<size; i++){
        //To check if the array element is even or odd
        if(arr[i]%2 == 0){
            sumEven += arr[i];
        }
        else{
            sumOdd += arr[i];
        }
    }
    printf("The difference between sum of EVEN and ODD elements of Array\nSum of EVEN Elements of Array : %d\nSum of ODD Elements of Array  : %d",sumEven,sumOdd);

}
int main(){
    int arr[] = {64,84,21,36,17,90,77,10,48,55};
    int size = sizeof(arr)/sizeof(int);
    diffEvenOdd(arr,size);
    return 0;
}