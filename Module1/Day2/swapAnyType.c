#include<stdio.h>

void swap(void* a, void* b,size_t size){

    /* type casting the pointers a and b to unsigned char so 
    that every 1 byte of char content in the a & b can be swapped */

    unsigned char* x = (unsigned char*)a; //--typecasting
    unsigned char* y = (unsigned char*)b;

    for(size_t i=0; i<size; i++){
        //----Swapping
        unsigned char temp = x[i]; 
        x[i] = y[i];
        y[i] = temp;

    }

}

int main(){

    int a=1, b= 2;
    printf("\nBefore Integer swap : %d  %d\n",a,b);
    swap(&a,&b,sizeof(int));
    printf("After Integer swap  : %d  %d\n\n",a,b);

    float x =3.4,y=6.6;
    printf("Before Float swap : %0.2f  %0.2f\n",x,y);
    swap(&x,&y,sizeof(float));
    printf("After Float swap  : %0.2f  %0.2f\n\n",x,y);
    return 0;
}