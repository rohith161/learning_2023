#include <stdio.h>

// Function to print from 1 to n
void oneToN(int i){
    for(int j=1; j<=i; j++){
            printf("%d",j);
        }
}

// Function to print from n to 1
void NToOne(int i){
    for(int k=i; k>=1; k--){
            printf("%d",k);
        }
}
// Function to print n spaces in between
void space(int i,int n){
    for(int s=0; s<(n-i); s++){
        printf("  ");
    }
}
// Function to print pattern
void pattern1(int n){
    for(int i=n; i>=1; i--){
        oneToN(i);
        space(i,n);
        NToOne(i);
        printf("\n");
    }
}
void pattern2(int n){
    for(int i=i; i<=n; i++){
        oneToN(i);
        space(i,n);
        NToOne(i);
        printf("\n");
    }
}


int main()
{
    int n = 5;
    // printf("Enter the n number for the pattern : ");
    // scanf("%d",&n);
    pattern1(n); 
    return 0;      
}