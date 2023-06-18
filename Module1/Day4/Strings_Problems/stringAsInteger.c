#include <stdio.h>
#include <string.h>

int stringToInteger(char* str){
    int integer = 0;
    sscanf(str,"%d",&integer);
    return integer;
}
int strInt(char* str){
    int integer = 0;
    for(int i=0; i<strlen(str); i++){
        int res = str[i] - '0';  // character manipulation
        integer = (integer * 10) + res; // arithemetic operation to get every digits in their place
    }
    return integer;
}
int main(){
    char str[] = "5278";
    // int num = atoi(str);  // atoi() can also be used for conversion which as less time complexity
    // int num = stringToInteger(str);  // sscanf() also provide conversion by format specifier which as more time complexity than atoi
    // printf("%d\n",num);
    int n = strInt(str); // This fucntion provides the character manipulation and arithmetic operation which has more time comlecity than atoi and sscanf
    printf("%d",n);
    return 0;
}