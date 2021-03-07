#include "stdio.h"
#include "string.h"

#define len 32

void main(){
    char matrix_string[3][len] = {'0'}, str[len] = {'0'};

    for (int m=0; m<3; m++){
        printf("输入单个字符串 %d: ", m + 1);
        scanf("%s", matrix_string[m]);
    }

    for (int x=0; x<3; x++){
        for (int y=0; y<3; y++){
            if (strcmp(matrix_string[x], matrix_string[y]) > 0)
                strcpy(str, matrix_string[x]);
        }
    }

    for (int m=0; m<3; m++){
        puts(matrix_string[m]);
    }

    printf("The max string is %s\n", str);
}