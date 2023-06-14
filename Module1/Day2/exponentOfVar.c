#include <stdio.h>

void printExponent(double x) {
    // Interpret the double as an unsigned long long to access its binary representation
    unsigned long long* xptr = (unsigned long long*)&x;
    unsigned long long value = *xptr;
    
    // Extract the exponent bits
    unsigned long long exponent = (value >> 52) & 0x7FF;
    
    // exponent in hexadecimal format
    printf("Exponent in hexadecimal: 0x%llx\n", exponent);
    
    //  exponent in binary format
    printf("Exponent in binary: 0b");
    for (int i = 11; i >= 0; i--) {
        printf("%d", (exponent >> i) & 1);
    }
    printf("\n");
}

int main() {
    double x = 0.7;
    
    printExponent(x);
    
    return 0;
}
