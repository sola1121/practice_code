#include "stdio.h"

/*
    dd吃桃, 第1天摘下若干个桃子, 吃了一半多一个; 第2天又吃了一半多一个; 
    以此循环, 每天都吃了前一天剩下的一半多一个, 直到第10天, 就剩一个桃子了
    求网友给了这位dd多少桃.
*/


int main(){
    int total = 0, remain = 1;
    for(int day=9; day>0; day--){
        total = (remain + 1) * 2;
        remain = total;
    }

    printf("网友一共给了这位dd: %d 个桃子.\n", total);

    return 0;
}