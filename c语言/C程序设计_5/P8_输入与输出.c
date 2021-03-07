#include <stdio.h>

// 用于返回两者之间的最大值
int max(int x, int y){
    if (x >= y){
        return x;
    } else {
        return y;
    }
}

int main(){
    int a, b;
    scanf("%d, %d", &a, &b);   // 标准的格式化输入, 所输入的是格式字符串, 不能有其他的
    printf("bigger number is %d\n", max(a, b));   // 标准的格式化输出
    return 0;
}