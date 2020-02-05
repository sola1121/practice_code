#include <stdio.h>

// 输入三个整数, 输出最大的

int max(int a, int b, int c){
    int temp;
    if (a>b){
        temp = a;
    } else {
        temp = b;
    }
    if (temp>c){
        return temp;
    } else {
        return c;
    }
}

void main(){
    int a, b, c;
    scanf("%d, %d, %d", &a, &b, &c);
    printf("%d\n", max(a, b, c));
}