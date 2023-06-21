#include <stdio.h>

typedef struct Demo{
    int x;
    int y;
}Demo;

// function to display the stucture fiels
void display(Demo* n1,Demo* n2){
    printf("\nn1\nx = %d\ny = %d\n",n1->x,n1->y);
    printf("\nn2\nx = %d\ny = %d\n\n",n2->x,n2->y);
}
// function to swap the two structure fields
void swapFields(Demo* n1, Demo* n2){
    // storing the n1 firls in temp
    Demo temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main(){
    Demo n1 = {1,2}, n2 = {3,4};
    display(&n1,&n2);
    swapFields(&n1,&n2);
    display(&n1,&n2);
    return 0;
}