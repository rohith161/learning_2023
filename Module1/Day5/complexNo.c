#include <stdio.h>

// Structure Complex Number
typedef struct ComplexNO {
    float real;
    float imag;
}ComplexNO;

// Function to read a complex number
 ComplexNO readComplex() {
    ComplexNO c;
    printf("Enter the real part: ");
    scanf("%f", &c.real);
    printf("Enter the imaginary part: ");
    scanf("%f", &c.imag);
    return c;
}

// Write a complex number
void writeComplex(ComplexNO n) {
    printf("Complex number: %.2f + %.2fi\n", n.real, n.imag);
}

// Add two complex numbers
ComplexNO addComplex(ComplexNO n1, ComplexNO n2) {
    ComplexNO sum;
    sum.real = n1.real + n2.real;
    sum.imag = n1.imag + n2.imag;
    return sum;
}

// Multiply two complex numbers
ComplexNO multiplyComplex(ComplexNO n1, ComplexNO n2) {
    ComplexNO product;
    product.real = n1.real * n2.real - n1.imag * n2.imag;
    product.imag = n1.real * n2.imag + n1.imag * n2.real;
    return product;
}

int main() {
    ComplexNO n1, n2;
    
    printf("Enter the first complex number:\n");
    n1 = readComplex();
    
    printf("Enter the second complex number:\n");
    n2 = readComplex();
    
    printf("\n");
    
    printf("First complex number:\n");
    writeComplex(n1);
    
    printf("Second complex number:\n");
    writeComplex(n2);
    
    printf("\n");
    
   ComplexNO sum = addComplex(n2, n2);
    printf("Sum of the two complex numbers:\n");
    writeComplex(sum);
    
    ComplexNO product = multiplyComplex(n2, n2);
    printf("Product of the two complex numbers:\n");
    writeComplex(product);
    
    return 0;
}
