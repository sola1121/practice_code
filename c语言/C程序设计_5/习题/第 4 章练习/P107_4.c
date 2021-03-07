#include "stdio.h"

int main(){
    int a, b, c;
    printf("输入三个数: ");
    scanf("%d%d%d", &a, &b, &c);

    a = b>a?b:a;
    a = c>a?c:a;
    printf("三个数中较大的是: %d\n", a);

    return 0;
}
