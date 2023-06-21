#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stringParse.h"

int main(){
    int size = 0;
    printf("Enter the size of the Students : ");
    scanf("%d",&size);

    // User is able to define the size of the array structure dynamicaaly
    Student* students = (Student*)calloc(size,sizeof(Student));
    printf("Enter the Students Details : \n(RollNo Name Marks)\n");
    getchar(); // to comsume the newline character

    // to get the number of inputs based on thew user
    for(int i=0; i<size; i++){
        int rollno = 0;
        char name[20];
        float marks = 0;
        char str[100];
        printf("\nStudent %d\n",i+1);
        fgets(str,sizeof(str),stdin);
        sscanf(str,"%d %s %f",&rollno,name,&marks);
        initStudent(&students[i],rollno,name,marks);
        printf("Enter 1 to continue, 0 Exit : ");
        int in = 0;
        scanf("%d",&in);
        if(0 == in){
            size = i+1;
            break;
        }
         getchar();
    }

    
    printf("\nStudents Details Before Sorting Descending order based marks\n--------------------------------\n");
    // to dIsplay the Student details
    displayAllStudent(students,size);
    printf("--------------------------------\n");
    // sorting the student in descending order based on their marks
    sortDescending(students,size);
    printf("Students Details After Sorting Descending order based marks\n--------------------------------\n");
    displayAllStudent(students,size);
    printf("--------------------------------\n");

    printf("Enter the student to search Name : ");
    char src[20];
    scanf("%s",src);
    // to search the student by name
    searchStudent(students,src,size);
    return 0;
}