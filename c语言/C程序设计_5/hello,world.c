#include <stdio.h>
#include <malloc.h>

void main(){
    printf("Hello,world.\n");

    // if(1){
    //     int a = 3;
    // }
    // printf("%d\n", a);
    // 以上不行

    // if (1){
    //     int a = (int) malloc(sizeof(int) *1);
    //     a = 3;
    // }
    // printf("%d\n", a);
    // 以上不行, 但在函数中可以返回

    // if (1) {
    //     static int a = 3;
    // }
    // printf("%d\n", a);
    // 以上不行, 但在函数中可以返回

    return 0;
}

// {}叫做语句块, 在语句块中定义的变量, 只在其所在语句中生存