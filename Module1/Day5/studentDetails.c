#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
    int id;
    char name[20];
    int age;
    int class;
}Student;

// function to store the student details 
void initStudent(Student *ptr,int id,char* name, int age, int class){
    ptr->id = id;
    strcpy(ptr->name,name);
    ptr->age = age;
    ptr->class = class;
}

// function to read the n number students details 
void readStudent(Student* ptr,int n){
    int id=0,age=0,class=0;
    char name[20];
    for(int i=0; i<n; i++){
        printf("Student %d\n",i+1);
        printf("Enter the id : ");
        scanf("%d",&id);
        printf("Enter the name : ");
        scanf("%s",name);
        printf("Enter the age : ");
        scanf("%d",&age);
        printf("Enter the class : ");
        scanf("%d",&class);
        initStudent(&ptr[i],id,name,age,class);
    }

}

//Function to display the n number Student details
void displayAllStudent(Student* ptr,int n){
    for(int i=0; i<n; i++){
        printf("\nStudent %d\n",i+1);
        printf("class : %d\n",ptr[i].class);
        printf("id : %d\n",ptr[i].id);
        printf("Name : %s\n",ptr[i].name);
        printf("age : %d\n",ptr[i].age);
        
    }
}
int main(){
    int n =0;
    printf("Enter the n Number students Data to be stored : ");
    scanf("%d",&n);
    Student* students = (Student*)calloc(n,sizeof(Student));
    readStudent(students,n);
    displayAllStudent(students,n);
    free(students);
    return 0;
}