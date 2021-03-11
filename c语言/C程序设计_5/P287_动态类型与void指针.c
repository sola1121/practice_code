#include "stdio.h"
#include "stdlib.h"


const int limit = 60;


void check(int * pt, int len){
    printf("低于limit的: \n");
    while(len-->0){
        if ((*pt)<limit)
            printf("%d  ", *pt);
        ++pt;
    }
}


int main(){
    int *p_arr;

    // p_arr = malloc(5 * sizeof(int));
    p_arr = (int*) malloc(5 * sizeof(int));   // 开辟动态内存区, 将地址转换成int*型, 然后放在p_arr中

    printf("输入5个值: \n");
    for (int i=0; i<5; i++)
        scanf("%d", p_arr+i);

    check(p_arr, 5);

    printf("\n");
    return 0;
}

/*
    使用malloc开辟了一段连续的内存, p_arr指向该地址头, 使用p_arr+i来遍历这段地址, 可以向其中存取值.

    malloc 返回的就是一个 void* 指针, 其类型和NULL 相同, 可以用来强制转换为任何其他类型的指针
*/