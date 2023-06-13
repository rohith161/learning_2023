#include <stdio.h>

void calculator(float num1,float num2,char operator){
    // fetching the operands values
    printf("Enter the Number 1 : ");
    scanf("%f",&num1);
    printf("Enter the operator : ");
    scanf(" %c",&operator);
    printf("Enter the Number 2 : ");
    scanf("%f",&num2);

    float result ;
    // operator operator using switch case
    switch (operator){
    case '+' : result = (float)(num1 + num2);
        break;
    case '-' : result = (float)(num1 - num2);
        break;
    case '*' : result = (float)(num1 * num2);
        break;
    case '/' : result = (float)(num1 / num2);
        break;
    default: printf("Invalid Operation");
        return;
    }

    // result
    printf("The Result of (%0.2f %c %0.2f) = %0.2f",num1,operator,num2,result);
}

int main(){
    float num1=0,num2=0;
    char operator;
    calculator(num1,num2,operator);
    return 0;
}
