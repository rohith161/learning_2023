#include <stdio.h>
#include <string.h>
#include <ctype.h>
// Function for file copy in upper case
void changeToUpperCase(FILE* srcFile,FILE* destFile){
    // buffer to store the content for each every line
    char buffer[1024];
    while(fgets(buffer,sizeof(buffer),srcFile) != NULL){
        fputs(strupr(buffer),destFile);
    }
}
// function to file copy in lower case
void changeToLowerCase(FILE* srcFile,FILE* destFile){
    // buffer to store the content for each every line
    char buffer[1024];
    while(fgets(buffer,sizeof(buffer),srcFile) != NULL){
        fputs(strlwr(buffer),destFile);
    }
}
// function to file copy in senstence case
void changeToSentenceCase(FILE* srcFile,FILE* destFile){
    char ch;// buffer character to store every character fetched from src file using fgetc
    char previousChar = ' '; // to sotore the previous character
    while((ch = fgetc(srcFile)) != EOF){
        if(previousChar == ' ' || previousChar == '.' || previousChar == '!' || previousChar == '?'|| previousChar == '\n'){
            fputc(toupper(ch),destFile);
        }
        else{
            fputc(tolower(ch),destFile);
        }
        previousChar = ch;
    }
}
// function to normal file copy
void copyFile(FILE* srcFile,FILE* destFile){
    // buffer to store the content for each every line
    char buffer[1024];
    while(fgets(buffer,sizeof(buffer),srcFile) != NULL){
        fputs(buffer,destFile);
    }
}

int main(){
    FILE *srcFile, *destFile;
    char srcName[150],destName[150];

    printf("Enter the Source File name/path with Extension : ");
    scanf("%s",srcName);
    srcFile = fopen(srcName,"r");

    printf("Enter the Destination File name/path with Extension : ");
    scanf("%s",destName);
    destFile = fopen(destName,"rw+");

    // if the sourec or destination file doesn't exit then this msg is shown
    if(srcFile == NULL || destFile == NULL){
        if(srcFile == NULL)
        {
            printf("File Name not found/Unable open the File \"%s\" .....\n",srcName);
        }
        if (destFile == NULL)
        {
            printf("File Name not found/Unable open the File \"%s\" .....\n",destName);
        }
        
        printf("File Copy Opearation Terminated...\n");
        return 0;
    }
    char format [2];
    printf("Please select one of the following options to copy the content in a formatted manner:- \n");
    printf("-u, to change file content to Upper Case\n");
    printf("-l, to change file content to Lower Case\n");
    printf("-s, to change file content to Sentence Case\n");
    printf("For normal Copy operation press any key and Enter\n:: ");
    scanf("%s",format);

    // Text Case formatted if else case
    if(strcmp(format,"-u") == 0)
    {
        changeToUpperCase(srcFile,destFile);
    }
    else if(strcmp(format,"-l") == 0)
    {
        changeToLowerCase(srcFile,destFile);
    }
    else if(strcmp(format,"-s") == 0)
    {
        changeToSentenceCase(srcFile,destFile);
    }
    else{
        copyFile(srcFile,destFile);
    }

    fclose(srcFile);
    fclose(destFile);

    printf("File Copy Operation Completed...\n");
    return 0;
}