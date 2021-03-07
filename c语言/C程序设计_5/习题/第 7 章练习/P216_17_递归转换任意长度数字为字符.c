#include "stdio.h"
#include "stdlib.h"

/*
    输入整数n, 转换为字符串. 使用递归.
*/


void int2str(int n){
    int i;
    if ( (i=n/10)!=0 )   // 一直除以10
        int2str(i);
    putchar(n%10+'0');
    putchar(32);   // 输出空格
}


int main(){
    int number=0;
    printf("输入整数: ");
    scanf("%d", &number);

    printf("输出: ");

    if (number<0){   // 如果是负数, 人为的输出负号
        putchar('-'); putchar(' ');
        number = -number;
    }
    int2str(number);
    printf("\n");

    return 0;
}