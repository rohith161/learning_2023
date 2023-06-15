#include <stdio.h>

void printBits(int n) {
    printf("The 32-bits of the %d Integer: ", n);

    // iterate over the every 32 bits of the Integer
    for (int i = 31; i >= 0; i--) {
        // ---- checking every bits of the n by i values 
        printf("%d", (n >> i) & 1); 
    }
}

int main(){
    int n = 0;
    printf("Enter the 32-bit Integer : ");
    scanf("%d",&n);
    printBits(n); 
    return 0;
}

