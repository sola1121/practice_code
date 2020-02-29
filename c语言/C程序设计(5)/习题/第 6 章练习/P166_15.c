#include "stdio.h"
#include "string.h"

#define len 128

/*
    复制一个数组到另一个, 不用strcpy, \0也要复制, 但后面不
*/

void main(){
    char str1[len] = "", *str2 = "0123456789abcdefghijklmnopqrstuvwxyz";

    for (int i=0; str2[i]!='\0'; i++){
        str1[i] = str2[i];
    }

    printf("%s \n", str1);
}