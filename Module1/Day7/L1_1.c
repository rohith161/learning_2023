#include <stdio.h>
int copyFiles(const char*, const char*);
FILE* openFile(const char*, const char*);

int main(){
    char srcName[150], destName[150];
    int flag = copyFiles(srcName, destName);
    if (flag == 0) {
        printf("Content of \"%s\" Copied to \"%s\" .....\nFile Copy Operation Completed....\n", srcName, destName);
    }
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
    char buffer[1024];
    while (fgets(buffer,sizeof(buffer),srcFile) != NULL) {
        fputs(buffer, destFile);
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
