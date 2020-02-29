#include "stdio.h"
#include "string.h"
#include "math.h"

/*
    比较字符串, 和strcpy差球不多
*/

void main(){
    char *str1 = "And", *str2 = "Aid";

/*
    char str1[128]="", str2[128]="";
    fgets(str1, 128, stdin);
    fgets(str2, 128, stdin);
*/

    int min_len = strlen(str1) > strlen(str2) ? strlen(str2) : strlen(str1),
        differ = 0;
    
    for (int i=0; i<min_len; i++){
        differ = fabs(str1[i]) - fabs(str2[i]);
        if (differ == 0){
            continue;
        } else {
            break;
        }
    }

    if (differ == 0){
        if (strlen(str1) == strlen(str2))   // 两个字符串相同
            printf("二者相同%d\n", differ);
        else {
            printf("两者因为长度原因不同\n");
        }
    } else {
        printf("两者不同, 相差%d\n", differ);
    }
    
}