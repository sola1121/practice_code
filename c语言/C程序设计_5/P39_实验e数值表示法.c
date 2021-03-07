#include <stdio.h>

int main(){
    char* s = "hello";  // 向指针赋值字面量地址.
    float num = 2.4e-3;
    printf("%s! num is %f \n", s, num);

    // 是否可以使用后128~255位的字符, 是否定的
    unsigned char c = 130;
    printf("%u  %c \n", c, c);
    return 0;
}