#include "stdio.h"
#include "stdlib.h"
#include "time.h"


// 将指向两个整型变量的指针变量作为实参传递给函数的形参指针变量, 在函数中通过指针实现交换两个变量
void swap(int *p1, int *p2){
    /*
        使用*获取指针变量指向的数据值, 然后交换, 这样指向的数据也会交换了. 
        但是注意, 因为是交换原来指向的值, 而不是交换指针变量, 这里的指向的地址还是没变, 只是其指向的值变了.
        以此, 可以通过函数更改其他地方的在生存期内的变量.

        temp变量不是指针, 如果使用*temp = *p1, 这将会出错, 因为temp没有初始化值, 他的值应给是一个存在的地址值.
    */
    int temp;
    temp = *p1;  // 注意这里的temp, 不是指针
    *p1 = *p2;
    *p2 = temp;
}


int main(){
    srand((unsigned) time(NULL));
    int a = rand()/10e6, b = rand()/10e6;
    int *pt1, *pt2;

    printf("a: %d, b: %d\n", a, b);

    pt1 = &a;
    pt2 = &b;

    printf("%p a: %d, %p b: %d\n", pt1, a, pt2, b);
    swap(pt1, pt2);
    printf("%p a: %d, %p b: %d\n", pt1, a, pt2, b);

    return 0;
}