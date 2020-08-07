#include "stdio.h"

/*
    指向指针数据的指针变量. 
    char **p;  *运算符是从右到左运算的, 可以写作 char *(*p);
    分作两部分来看 char*与*p, (*p)表示p是指针变量, char*表示p指向的是char*类型的数据.
    也就是说, p指向一个字符指针变量(这个字符指针变量指向一个字符型数据).
    如果引用*p, 就得到p所指向的字符指针变量的值.
*/


int main(){
    char * name[] = {"Python", "Golang", "C", "JavaScript", "Html"};
    char ** ppt;
    int i;
    for(i=0; i<5; i++){
        ppt = name+i;
        printf("%s\n", *ppt);
    }

    int arr[5] = {1, 2, 3, 4, 5};
    int *num[5];
    int **ppt2;
    for(i=0; i<5; i++)
        num[i] = &arr[i];

    return 0;
}