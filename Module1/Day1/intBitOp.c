#include <stdio.h>

int bit_operations(int num, int oper_type) {

    // inputs
    printf("Enter the Number : ");
    scanf("%d",&oper_type);
    printf("Enter the Operator Type : ");
    scanf("%d",&oper_type);

    //Bit operation
    switch (oper_type) {
        case 1:  // Set 1st bit
            num |= 1;
            break;
        case 2:  // Clear 31st bit
            num &= ~(1 << 30);
            break;
        case 3:  // Toggle 16th bit
            num ^= 1 << 15;
            break;
        default:
            printf("Invalid operation type.\n");
            break;
    }
    return num;
}

int main() {
    int num ,oper_type ;
    int result = bit_operations(num, oper_type);
    printf("Result: %d\n", result);
    return 0;
}

