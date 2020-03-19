#include "stdio.h"
#include "stdlib.h"
#include "time.h"


void main(){
    srand((unsigned) time(NULL));

    int max(int, int, int);   // 函数声明
    extern A, B, C;   // 在此引入变量A, B, C的作用域, 有点类似上面的函数声明

    A = (int) rand()/10e7;
    B = (int) rand()/10e7;
    C = (int) rand()/10e7;
    printf("A=%d, B=%d, C=%d, max=%d\n", A, B, C, max(A, B, C));
}

int A, B, C;

int max(int a, int b, int c){
    int max_num = a>b?a:b;
    max_num = max_num>c?max_num:c;
    return max_num;
}