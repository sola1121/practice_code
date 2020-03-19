#include "stdio.h"

/*
    auto 默认, 使用动态存储区
    static , 使用静态存储区, 在完成定义变量时, 就会一直存在, 直到程序生存期结束
    register , 使用CPU寄存器, 现代编译器都可以自动决定使用动态存储还是CPU寄存的方式, 这种方式就是读写无中间商损耗速度

    注意区分存储方式与作用域, 一个是表示变量的在内存中的存储方式, 关乎着其存续时间; 另一个是表示其能否在这个函数中使用.
*/

int num4 = 4;   // 全局变量, 使用静态存储区域

int auto_static_register_variate(int num){
    auto int num1 = 1;       // 默认的变量定义都是auto, 使用动态存储区, int num1 = 1
    static int num2 = 2;     // 使用静态存储区, 当所在函数第一次调用时, 就会在静态存储区一直有这么一个变量, 直到程序结束, 但是其作用域只在该函数中哦
    register int num3 = 3;   // 使用CPU寄存器, 类似动态存储区, 但是使用的是CPU的存储单元, 就很快
    num1 = num1 + 1;
    num2 = num2 + 1;
    num3 = num3 + 1;
    printf("┍num1=%d, num2=%d, num3=%d\n", num1, num2, num3);   // num2 : 3, 4, 5, 每一次结果都对应上一次结果+1
    return num1 + num2 + num3 + num;
}

int main(){
    for (int i=10; i<=30; i+=10)
        printf("func(%d) retrun %d\n\n", i, auto_static_register_variate(i));

    return 0;
}