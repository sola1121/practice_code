#include "stdio.h"


void main(){
    extern Global;
    extern int power(int);   // 函数声明, 引入extension中的power函数, 也可以省略extern

    Global = 2;   // 定义全局变量的值

    printf("%d\n", power(4));

}