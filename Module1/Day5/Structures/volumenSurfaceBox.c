#include <stdio.h>

typedef struct Box
{
    float length;
    float width;
    float height;
}Box;

float Volume(Box* ptr){
    // formula to calculate the Volume of the box (L * W * H)
    return ptr->length * ptr->width * ptr->height;
}
float surfaceArea(Box* ptr){
    // formula to calculate the Volume of the box 2*((L * W) + (L * H) + (W * H))
    return 2 * ((ptr->length * ptr->width) + (ptr->length * ptr->height) + (ptr->width * ptr->height));
}
int main(){
    // intilaze the Box Stucture
    Box box;
    // Assigning the dimemsion of the box
    box.length = 5;
    box.height = 3;
    box.width = 2;
    float volume = Volume(&box);
    float surArea = surfaceArea(&box);
    printf("Volume of Box : %0.2f\nSurfaceArea of the Box : %0.2f : \n",volume,surArea);
    return 0;
}