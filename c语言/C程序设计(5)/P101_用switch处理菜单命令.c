#include "stdio.h"


void func1(int a, int b){
    printf("功能1调用. a+b= %d\n", a+b);
}


void func2(int a, int b){
    printf("功能2调用. a-b= %d \n", a-b);
}


int main(){
    char ch;
    int x = 15, y = 29;

    switch(ch=getchar()){
    case 'a':
    case 'A':
        func1(x, y);
        break;
    case 'b':
    case 'B':
        func2(x, y);
        break;
    default:
        printf("只接受单个字符a,b.\a");
    }

    putchar('\a');

    return 0;
}
