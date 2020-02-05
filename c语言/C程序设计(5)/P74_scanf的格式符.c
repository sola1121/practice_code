#include "stdio.h"
/*
   scanf(格式控制, 地址列表)
   如果在各市控制字符串中除了格式声明以外还有其他字符,
   则在输入数据时在对应的位置上应输入与这些字符相同的字符
*/

int main(){
    int a;
    unsigned int b;
    long long b1;
    float c;
    double d;
    char ch;
    char *s;

    printf("1. 输入十进制数\n2. 输入浮点数\n3. 输入单个字符\n4. 输入字符串\n\
5. 输入string流\n6. 输入长整型, 双精度\n");
    scanf("%d", &a); printf("%d \n", a);
    scanf("%f", &c); printf("%f \n", c);
    scanf("%c", &ch); printf("%c \n", ch);
    scanf("%s", &s); printf("%s \n", s);
    scanf("%ld,%lf", &b1, &d); printf("%ld   %lf \n", b1, d);

    return 0;
}
