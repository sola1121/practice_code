#include "stdio.h"

/*
    指向指针数据的指针变量. 
    char **p;  *运算符是从右到左运算的, 可以写作 char *(*p);
    分作两部分来看 char*与*p, (*p)表示p是指针变量, char*表示p指向的是char*类型的数据.
    也就是说, p指向一个字符指针变量(这个字符指针变量指向一个字符型数据).
    如果引用*p, 就得到p所指向的字符指针变量的值.

    如果有int *num[5], 其中元素指向不同地址的int, 使用一个指针的指针来遍历它.
    int **p;  为了得到num[2]中的数据, 可以先使p=num+2, 然后输出**p.
    注意, *p是num[2]的值, 而num[2]的值是一个int变量的地址, 因此**p是num[2]元素指向的int的值.
*/


int main(){
    /* 指针数组元素指向字符串 */
    char * name[] = {"Python", "Golang", "C", "JavaScript", "Html"};
    char* *ppt;
    int i;
    for(i=0; i<5; i++){
        ppt = name+i;
        printf("%s\n", *ppt);
    }
    printf("\n");


    /* 指针数组元素指向整形数据 */
    int arr[5] = {1, 2, 3, 4, 5};
    int * num[5];
    int* *ppt2;
    ppt2 = num;   // 使ppt2指向num[0]

    // 使* num[5] = {&arr[0], &arr[1], &arr[2], &arr[3], &arr[4]}; 
    for(i=0; i<5; i++)
        num[i] = &arr[i];   // num是存储指针的数组, 用arr各元素的地址为其元素赋值

    for(i=0; i<5; i++){
        printf("%d ", **ppt2);
        ppt2++;
    }

    printf("\n");
    return 0;
}