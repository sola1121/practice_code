#include "stdio.h"

int main(){
    char c;
    c = getchar();
    if (c >= 'a' && c <= 'z'){
        printf("输入的是小写字母, 转换为大写: %c\n", c-32);
    } else if (c >= 'A' && c <= 'Z'){
        printf("输入的是大写字母, 转换为小写: %c\n", c+32);
    } else {
        printf("你应该输入一个字母.\n");
    }

    c>='A'&&c<='Z' ? printf("是大写字母.\n") : printf("是小写字母.\n");   // 只能在里面写一个表达式
    return 0;
}
