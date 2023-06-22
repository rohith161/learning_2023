#include <stdio.h>

int main(){
    FILE *srcFile, *destFile;
    // to store the file Name or their Location address
    char srcName[150],destName[150];

    printf("Enter the Source File name/path with Extension : ");
    scanf("%s",srcName);
    srcFile = fopen(srcName,"r");

    printf("Enter the Destination File name/path with Extension : ");
    scanf("%s",destName);
    destFile = fopen(destName,"rw+");

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
    // buffer to store the content for each every line
    char buffer[1024];
    while (fgets(buffer,sizeof(buffer),srcFile) != NULL)
    {
        fputs(buffer,destFile);
    }
    
    fclose(srcFile);
    fclose(destFile);

    printf("Content of \"%s\" Copied to \"%s\" .....\nFile Copy Operation Completed....\n",srcName,destName);
    return 0;
}