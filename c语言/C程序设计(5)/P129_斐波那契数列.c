#include "stdio.h"
#include "time.h"

// 1 1 2 3 5 8 13 21 ...
// 输入项数n, 输出其所在位置的数

unsigned int fab_recursion(int n){
    // 使用递归的方式求
    if (n <= 1)
        return 1;
    return fab_recursion(n-1) + fab_recursion(n-2);
}


unsigned int fab_loop(int n){
    // 使用循环的方式求
    unsigned int  num1 = 1, num2 = 1, num3;
    if (n <= 1)
        return 1;
    for (int i=2; i<=n; i++){
        num3 = num1 + num2;
        num1 = num2;
        num2 = num3;
    }
    return num3;
}


void main(){
    clock_t start_time;

    int limit;
    printf("输出数列到多少位: ");
    scanf("%d", &limit);

    start_time = clock();
    // 使用递归, 注意, 项的下标是从0开始的
    for (int i=0; i<limit; i++){
        printf("%ld  ", fab_recursion(i));
        if ((i+1) % 5 == 0)
            printf("\n");
    }
    printf("CPU用时: %f\n", ((float)clock()-start_time)/CLOCKS_PER_SEC);

    printf("\n==============\n");

    start_time = clock();
    // 使用循环, 注意, 项的下表是从0开始的
    for (int i=0; i<limit; i++){
        printf("%ld  ", fab_loop(i));
        if ((i+1) % 5 == 0)
            printf("\n");
    }
    printf("CPU用时: %f\n", ((float)clock()-start_time)/CLOCKS_PER_SEC);
    
}