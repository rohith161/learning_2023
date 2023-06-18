#include <stdio.h>
#include <string.h>

void rotateString(char* str,int k,int dir){
    int size = strlen(str);
    //printf("%s --> ",str);
    if(dir == 0){
        char temp[k];
        strncpy(temp,str,k);
        temp[k] ='\0';
        strncpy(str,str+k,(size)-k);
        str[(size)-k] = '\0';
        strcat(str,temp);
    }
    else{
        int div = size-k;
        char temp[div];
        strncpy(temp,str,div);
        temp[div] = '\0';
        strncpy(str,str+div,k);
        str[k] = '\0';
        strcat(str,temp);
        
    }
    printf("%s\n",str);
}

int main(){
    char str1[] = "abcdxyz";
    char str2[] = "abcdxyz";
    // direction left = 0 and right = 1
    int k = 2,direction = 0; // left 
    rotateString(str1,k,direction);
    k = 3, direction = 1; // right
    rotateString(str2,k,direction);
    return 0;
}