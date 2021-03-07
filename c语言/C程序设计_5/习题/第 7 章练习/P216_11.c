#include "stdio.h"

/*
    冒泡排序字符串
*/

#define length 10


void sort_string(char *string){
    char temp;
    for (int m=0; m<length-1; m++){
        for (int n=0; n<length-m-1; n++){
            if (string[n] > string[n+1]){
                temp = string[n];
                string[n] = string[n+1];
                string[n+1] = temp;
            }
        }
    }
}


int main(){
    char str[length] = "lf3UJruPo8";

    sort_string(str);
    printf("%s\n", str);

    return 0;
}