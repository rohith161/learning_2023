#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void CopyFile(char** );
void changeToUpperCase(FILE*, FILE*);
void changeToLowerCase(FILE*, FILE*);
void changeToSentenceCase(FILE*, FILE*);
void normalCopyFile(FILE*, FILE*);

int main(int arg,char* argv[]){
    (void)arg;
    CopyFile(argv);
}

void CopyFile(char** argv){
    int flag = 1;
    char format[50];
    strcpy(format,argv[1]);
    FILE* srcFile = fopen(argv[2],"r");
    if(srcFile == NULL){
        printf("The source File \"%s\" NOT FOUND/Unable to open \n",argv[2]);
        flag = 0;
    }
    FILE* destFile = fopen(argv[3],"w");
    if(destFile == NULL){
        printf("The source File \"%s\" NOT FOUND/Unable to open \n",argv[3]);
         flag = 0;
    }
    // Text case formatted if-else cases
    if (strcmp(format, "-u") == 0) {
        changeToUpperCase(srcFile, destFile);
    }
    else if (strcmp(format, "-l") == 0) {
        changeToLowerCase(srcFile, destFile);
    }
    else if (strcmp(format, "-s") == 0) {
        changeToSentenceCase(srcFile, destFile);
    }
    else {
        normalCopyFile(srcFile, destFile);
    }

    fclose(srcFile);
    fclose(destFile);
    printf("%s",(flag == 1)?"Copy Operation was Successful\n":"Copy Operation was Terminated\n");
}

// Function for file copy in upper case
void changeToUpperCase(FILE* srcFile, FILE* destFile) {
    char buffer[1024];
    while (fgets(buffer,sizeof(buffer),srcFile) != NULL) {
        fputs(strupr(buffer), destFile);
    }
}

// Function for file copy in lower case
void changeToLowerCase(FILE* srcFile, FILE* destFile) {
    char buffer[1024];
    while (fgets(buffer,sizeof(buffer),srcFile) != NULL) {
        fputs(strlwr(buffer), destFile);
    }
}

// Function for file copy in sentence case
void changeToSentenceCase(FILE* srcFile, FILE* destFile) {
    int previousChar = ' '; // Flag to capitalize the first character
    int ch;
    while ((ch = fgetc(srcFile)) != EOF) {
        if(previousChar == ' ' || previousChar == '\n' || previousChar == '.'){
            fputc(toupper(ch), destFile);
        }
        else{
            fputc(tolower(ch), destFile);
        }
        previousChar = ch;
    }
}

// Function for normal file copy
void normalCopyFile(FILE* srcFile, FILE* destFile) {
    char buffer[1024];
    while (fgets(buffer,sizeof(buffer),srcFile) != NULL) {
        fputs(buffer, destFile);
    }
}
