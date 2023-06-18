#include <stdio.h>
#include <ctype.h>
#include <string.h>

void toggleCase(char* str){
    printf("The toggle Case of the given String \n%s -> ",str);

    for(int i=0; i<strlen(str); i++){
        // to if the character in the string is lower case or upper case
        if(islower(str[i])){
            str[i] = toupper(str[i]);
        }
        else if(isupper(str[i])){
            str[i] = tolower(str[i]);
        }
    }

    printf("%s\n",str);
}

int main(){
    char str1[] = "Hello World";
    char str2[] = "A+B";
    char str3[] = "Prog4u";
    toggleCase(str1);
    toggleCase(str2);
    toggleCase(str3);
    return 0;
}