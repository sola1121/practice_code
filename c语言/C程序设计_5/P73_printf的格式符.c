#include <stdio.h>

/*
  printf 与 scanf 都是由库stdio.h提供的, 其已经泛化为几乎标准的函数
  使用格式符就是这两个的核心玩法
  printf:
  -m.n格式符  -:输出的数字或字符域内向左靠   m:一个正整数,数据最小宽度   n:一个正整数,对实数表示输出的小数位, 对字符表示截取的字符个数

*/

int main(){
    char c = 'a';
    char *s = "a_string";
    int a = 1, a1 = -1;
    unsigned int b = 2;
    long long x = 996, x1 = -996;
    float y = 2233.23, y1 = -2233.23;
    double z = 2020.0128, z1 = -2020.0128;

    printf("%d \n", b);   // 输出一个有符号的十进制数
    printf("%ld \n", x);   // 长整型整数
    printf("%i \n", b);   // 按十进制整型数据的实际长度输出
    printf("%u \n", a);   // 以无符号十进制形式输出整数
    printf("signed: %o   unsigned: %o \n", x, x1);   // 以八进制无符号形式输出整数(不输出前导符0)
    printf("signed: %x   unsigned: %X \n", x, x1);   // 以十六进制输出整数(不输出前导符0x)
    printf("%c \n", c);   // 输出一个字符
    printf("%s \n", s);   // 输出字符串
    printf("%f \n", y);   // 以小数形式输出单,双精度数,隐含输出6位小数
    printf("%lf \n", z);  // 双精度, 若果使用.n, 那么n的最大值只能是15, 双精度只保证15位小数位 %.15f
    printf("%e   %E \n", z, z1);   // 以指数形式输出实数
    printf("%g   %G \n", y, y1);   // 选用%f或%e格式中输出宽度较短的一种格式, 不输出无意义的0
}
