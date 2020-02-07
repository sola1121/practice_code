#include "stdio.h"

/*
  putchar()输出单个字符, 如果给出一个整型, 将会转化为所使用字符集的对应字符
  getchar()从键盘缓冲中获取一个字符, Enter结束
*/

void main(){
    char x, y;
    int z;
    x = getchar();
    y = getchar();
    z = getchar();

    putchar('\n');
    putchar(x);
    putchar(y);
    z += 32;
    putchar(z);
    putchar('\n');
}
