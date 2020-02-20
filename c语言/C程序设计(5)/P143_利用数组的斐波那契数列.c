#include "stdio.h"

#define limit 20

int main(){
    // 小标需要为一个常数, 或常数表达式 , 部分赋值只能在初始化的时候做, 为第一和第二项赋值
    unsigned int fib[limit] = {1, 1};

    for (int i=2; i<limit; i++){
        fib[i] = fib[i-1] + fib[i-2]; 
    }

    for (int i=0; i<limit; i++){
        if (i % 5 == 0) printf("\n");
        printf("%6d", fib[i]);
    }

    printf("\n");
    return 0;
}