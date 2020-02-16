#include "stdio.h"

int is_prime(unsigned int num){
    int flag = 1;   // 默认为True, 是素数
    for (int i=2; i<num/2+1; i += 2){   // 其实到sqrt(num)就可以了
        if (num % i == 0){
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(){
    // 1. 判断素数
    unsigned int num, flag=1;
    printf("输入一个大于3的整数:");
    scanf("%d", &num);
    
    flag = is_prime(num);

    switch (flag){
    case 1:
        printf("这是一个素数.\n");
        break;
    case 0:
        printf("这不是一个素数.\n");
        break;
    }

    // 2. 输出100~200之间的素数
    for(num=100; num<=200; num++)
        if (is_prime(num))
            printf("%ld  ", num);

    return 0;
}