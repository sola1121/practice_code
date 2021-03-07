#include "stdio.h"
#include "string.h"

#define container 1024

void joint_string(char* str1, char*str2){
    char result[container] = " ";
    int str1_len = strlen(str1) - 1, str2_len = strlen(str2) - 1;
    if (str1_len + str2_len > container){
        printf("%s\n", "Error, out of container.");
    }
    for (int i=0; i<=str1_len; i++)
        result[i] = str1[i];
    for (int i=0; i<=str2_len; i++)
        result[str1_len+1+i] = str2[i];
    printf("%s\n", result);
}


void main(){
    char *str1 = "12345", *str2 = "67890";

    joint_string(str1, str2);

}