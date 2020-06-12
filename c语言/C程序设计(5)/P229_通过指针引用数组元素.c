#include "stdio.h"

/*
    数组名(不包括形参数组名)代表数组中首元素(即下标为0的元素)的地址.
    数组变量名可以看做就是一个指针变量, 其保存的地址就是数组首元素的地址.
*/

#define len 5

int main(){
    int array[len] = {100, 200, 300, 400, 500};
    int *pt1, *pt2;

    // 下面两个是等价的. 一个是获得数组首元素的地址, 另一个是直接赋值为数组名.
    pt1 = &array[0];
    pt2 = array;

    printf("pt1: %p, pt2: %p, 两个都指向了array的第一个元素.\n", pt1, pt2);

    return 0;
}