#include "stdio.h"
#include "ctype.h"
#include "string.h"

#define len 128

void main(){
    int count = 1, judge = 0;
    char str[len] = {'0'}, temp;
    printf("输入内容: ");
    fgets(str, len, stdin);

    // strcmp是用来对比char*指针的 
    for (int i=0; i<strlen(str); i++){
        if (isspace(str[i])){
            judge = i + 1;
            while (judge<strlen(str)){
                if (!isalpha(str[judge])){
                    ++ judge;
                } else {
                    count += 1;
                    break;
                }
            }
        }
    }

    printf("根据空格推测可能输入%d 个字符\n", count);


    count = 1;
    for (int i=0; (temp=str[i])!='\0'; i++){
        if (str[i] == ' ')
            count += 1;
    }

    printf("根据空格推测可能输入%d 个字符\n", count);
}