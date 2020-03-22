#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

/*
    输入16进制数, 求其对应的10进制数
*/

long hex2dec(char *hex_num){
    long dec_num=0, temp=0;
    for (int i=strlen(hex_num)-1, digit=0, sign=1; i>=0; i--, digit++){
        if ('A'<=hex_num[i] && hex_num[i]<='F'){
            temp = hex_num[i] - 55;
        } else if ('a'<=hex_num[i] && hex_num[i]<='f'){
            temp = hex_num[i] - 87;
        } else if ('0'<=hex_num[i] && hex_num[i]<='9'){
            temp = atol(&hex_num[i]);
        } else {
            printf("所输入包含非法字符.\n");
            return -1;
        }
        dec_num +=  temp * pow(16.0, (double)digit) * sign;
    }
    return dec_num;
}



int main(){

    char *num="-2AF5";

    printf("对应的十进制数: %ld\n", hex2dec(num));

    return 0;
}