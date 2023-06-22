#include <stdio.h>
#include <string.h>
#include <ctype.h>

int copyFiles(const char*, const char*);
FILE* openFile(const char*, const char*);
void textCaseformat(char*);
void changeToUpperCase(FILE*, FILE*);
void changeToLowerCase(FILE*, FILE*);
void changeToSentenceCase(FILE*, FILE*);
void normalCopyFile(FILE*, FILE*);

int main() {
    char srcName[150], destName[150];
    int flag = copyFiles(srcName, destName);
    printf("%s", (flag == 0) ? "File Copy Operation Completed...\n" : "");
    return 0;
}

int copyFiles(const char* srcName, const char* destName) {
    FILE* srcFile, * destFile;
    printf("Enter the Source File name/path with Extension: ");
    scanf("%s", srcName);
    srcFile = openFile(srcName, "r");

    printf("Enter the Destination File name/path with Extension: ");
    scanf("%s", destName);
    destFile = openFile(destName, "rw+");

    // If the source or destination file doesn't exist, show an error message
    if (srcFile == NULL || destFile == NULL) {
        if (srcFile == NULL) {
            printf("File \"%s\" not found/Unable to open the file...\n", srcName);
        }
        if (destFile == NULL) {
            printf("File \"%s\" not found/Unable to open the file...\n", destName);
        }

        printf("File Copy Operation Terminated...\n");
        return 1;
    }

    char format[3];
    textCaseformat(format);

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
    return 0;
}

FILE* openFile(const char* name, const char* type) {
    FILE* temp = fopen(name, type);
    if(temp == NULL){
        return NULL;
    }
    return temp;
}

void textCaseformat(char* format) {
    printf("Please select one of the following options to copy the content in a formatted manner:\n");
    printf("-u, to change file content to Upper Case\n");
    printf("-l, to change file content to Lower Case\n");
    printf("-s, to change file content to Sentence Case\n");
    printf("For normal Copy operation, press any key and Enter\n:: ");
    scanf("%s", format);
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
