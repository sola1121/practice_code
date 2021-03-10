#include "stdio.h"

/*
  int putchar(int c) 输出单个字符, 如果给出一个整型, 将会转化为所使用字符集的对应字符
  int getchar(void)从键盘缓冲中获取一个字符, Enter结束. 其不仅可以从输入设备获得一个可显示的字符, 而且可以获得在屏幕上无法像是的字符.
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