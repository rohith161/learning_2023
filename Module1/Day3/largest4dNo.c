#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void largestNo(const char* num[]){
    int num1=0, num2=0;

    sscanf(num[0],"%d-",&num1); // string to Integer conversion of num1
    sscanf(num[1],"%d-",&num2); // string to Integer conversion of num2

    printf("\nThe two 4 digit numbers\n%d , %d\n\n",num1,num2);
    // deleting the single digit 
    num1 /= 10; 
    num2 /= 10;
    printf("Largest number of above After deleting the single digit \n%d",(num1 > num2)?num1:num2);
    
}
int main(){
    const char* num[2] = {"5872-872","9856-986"};
    largestNo(num);
    return 0;
}
