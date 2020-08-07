# include "stdio.h"


int max(int a, int b){
    return a>b?a:b;
}

int min(int a, int b){
    return a>b?b:a;
}

int sum(int a, int b){
    return a + b;
}

int func(int a, int b, int (*f)(int, int)){   // int (*f)(int, int) 用于接受函数地址
    return (*f)(a, b);
}


int main(){
    int x=12, y=34, flag=0, result=0;


    start_func:
    printf("1.max 2.min 3.sum: ");
    scanf("%d", &flag);

    switch (flag){
    case 1:
        result = func(x, y, max);
        break;
    case 2:
        result = func(x, y, min);
        break;
    case 3:
        result = func(x, y, sum);
        break;
    default:
        printf("输入的选项不符合.\n");
        goto start_func;
        break;
    }

    printf("结果是: %d\n", result);

    return 0;
}