#include <stdio.h>
#include <string.h>

void studentDetails(char *rollNo,char* name,int* Phy,int* math,int* Chem){
    // Fetching Student details
    printf("\nEnter the Student RollNo\t: ");
    gets(rollNo); 
    printf("Enter the Student Full Name\t: ");
    gets(name);
    printf("Enter the Physics marks\t\t: ");
    scanf("%d",&(*Phy));
    printf("Enter the Math marks\t\t: ");
    scanf("%d",&(*math));
    printf("Enter the Chemistry marks\t: ");
    scanf("%d",&(*Chem));

    // percentage of three subjects
    float percentage = (((float)((*Phy) + (*math) + (*Chem)))/(float)300)*(float)100;
    
    // Student Summary
    printf("\n--- STUDENT SUMMARY---\n");
    printf("\nStudent Full Name\t: %s\n",name);
    printf("Roll No\t\t\t: %s\n",rollNo);
    printf("\nStudent Subject marks :- \n\n");
    printf("Phyics\t\t: %d\n",*Phy);
    printf("Math \t\t: %d\n",*math);
    printf("Chemistry\t: %d\n",*Chem);
    printf("\nOverall Student Percentage : %2.2f%% ",percentage);
   
}

int main(){
    int Phy=0,Math=0,Chem=0;
    char name[50],rollNo[50];
    studentDetails(rollNo,name,&Phy,&Math,&Chem);
    return 0;
}
