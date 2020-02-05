#include "stdio.h"

void main(){
    char c1, c2;
    c1 = getchar();
    c2 = getchar();

    // 1. 变量c1和c2应定义为字符型,整型还是二者皆可
    // 都可以

    // 2. 输出c1,c2值的ASCII码
    printf("c1 = %d, c2 = %d \n", c1, c2);

    // 3. 整型变量和字符变量是否在任何情况下都可以互相代替
    // 不能超过字符集大小
}
