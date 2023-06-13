#include <stdio.h>

void gradeStudent(int num){

    printf("Enter the Student Score : ");
    scanf("%d",&num);
    // Grading of the student
    printf("Student Grade -->  ");
    if(num >= 0 && num <=49){
        printf("Grade F");
    }
    else if(num >= 50 && num <=59){
        printf("Grade D");
    }
    else if(num >= 60 && num <=74){
        printf("Grade C");
    }
    else if(num >= 75 && num <=89){
        printf("Grade B");
    }
    else if(num >= 90 && num <=100){
        printf("Grade A");
    }
}

int main(){
    int num;
    gradeStudent(num);
    return 0;
}
