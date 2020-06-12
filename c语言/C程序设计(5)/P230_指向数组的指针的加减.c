#include "stdio.h"

/*
    数组在内存中是一个连续存在的地址集合, 可以通过指针的加减整数来调整指针指向的元素.
    数组数组的指针变量(包括他自身数组名)的加减, 不是简单地进行数字加减, 而是加上一个数组元素所占用的字节数.
    加多少字节数, 是通过在指针中记录的数据类型来判断的.

    使用下标和直接使用数组变量+索引效率是一样的. 但如果直接使用数组指针来遍历(这样指针变量就指向最后一个元素了, 类似iteration), 效率高一些.
    编译器编译时, 会将下标索引转换为使用数组指针加上一个数来处理.
*/

#define len 5

int main(){
    float array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    float *pt1, *pt2;

    // 已经指向其中的一个元素, 通过不超过范围的加减, 查看另一元素
    char * format = "pt1 标2: %p, 对应值: %.1f\npt1 + 1: %p, 对应值: %.1f\npt1 - 1: %p, 对应值: %.1f\n";
    pt1 = &array[2];   // 指向中间的元素
    printf(format, pt1, *pt1, pt1+1, *(pt1+1), pt1-1, *(pt1-1));

    // 因为数组名就是指针变量, 指向数组元素第一个, 所以也可以直接使用数组名加减
    format = "\narray+2: %p, 对应值: %.1f\narray+3: %p, 对应值: %.1f\narray+1: %p, 对应值: %.1f\n";
    printf(format, array+2, *(array+2), array+3, *(array+3), array+1, *(array+1));

    // 指向同一个数组的两个指针可以相减, 反应两者间相差多少个元素, 相加就无意义
    // 实际是两者地址相减, 再除以其类型字节数, 就是元素的个数了
    format = "\n指向array[4]的指针 - 指向array[0]的指针 = %d\n";
    pt1 = array + 4;
    pt2 = array;
    printf(format, pt1-pt2);

    // 使用循环来遍历数组, 数组指针副本自增
    printf("\n使用指针遍历数组:\n");
    for(pt2=array; pt2<(array+len); pt2++)   // 可以直接使用自增哦, 不能使用原数组变量, 因为其指向首元素地址, 是一个常量, 这是为了回收内存
        printf("当前地址: %p, 值: %.1f\n", pt2, *pt2);

    return 0;
}