
typedef struct Student
{
    int rollno;
    char name[20];
    float marks;
}Student;

void initStudent(Student* ptr,int rollno,char* name, float marks){
    ptr->rollno = rollno;
    strcpy(ptr->name,name);
    ptr->marks = marks;
}

void displayAllStudent(Student* ptr,int size){
    for(int i=0; i<size; i++){
        printf("RollNo : %d\n",ptr[i].rollno);
        printf("Name : %s\n",ptr[i].name);
        printf("Marks : %0.2f\n\n",ptr[i].marks);
    }
}

void swapStudents(Student *student1,Student *student2) {
    Student temp = *student1;
    *student1 = *student2;
    *student2 = temp;
}

void sortDescending(Student *ptr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (ptr[j].marks < ptr[j + 1].marks) {
                swapStudents(&ptr[j], &ptr[j + 1]);
            }
        }
    }
}


int searchStudent(Student* ptr,char* name,int size){
    for(int i=0; i<size; i++){
        if(strcmp(ptr[i].name,name) == 0){
            printf("\nStudent %s --> Name \"FOUND\"\n",name);
            printf("RollNo : %d\n",ptr[i].rollno);
            printf("Name : %s\n",ptr[i].name);
            printf("Marks : %0.2f\n",ptr[i].marks);
            return 1;
        }
    }
    printf("Student %s --> Name \"NOT FOUND\"\n",name);
    return 0;
}
