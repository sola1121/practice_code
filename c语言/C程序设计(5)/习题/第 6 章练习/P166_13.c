#include "stdio.h"
#include "string.h"

/*
    拼接字符串, 不用strcat, 模拟strcat
*/

void main(){
    char str1[32] = "abcdefghijklmnopqrstuvwxyz", str2[32] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 
         STR[64] = "";
    
    for (int i=0; i<strlen(str1); i++)
        STR[i] = str1[i];

    for (int i=strlen(str1); i<64; i++)
        STR[i] = str2[i-strlen(str1)];

    printf("%s\n", STR);
}