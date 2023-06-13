#include <stdio.h>

void findBiggestNo(int* x,int* y){
    printf("To Find the Biggest of Two Numbers \n");
    printf("Number 1 : ");
    scanf("%d",&(*x));
    printf("Number 2 : ");
    scanf("%d",&(*y));

    //comparing the x and y values
    printf("%s",(*x>*y)?"Number 1 is greater than Number 2":"Number 2 is greater than Number 1");
}

int main(){
    int x=0,y=0;
    findBiggestNo(&x,&y);
    return 0;
}
