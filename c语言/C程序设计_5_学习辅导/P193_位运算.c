# include "stdio.h"

/*  
    优先级2, 左←右, 单目运算符
    ~ 按位取反

    优先级5, 左→右, 双目运算符    
        << 左移
        >> 右移

    优先级8, 左→右, 双目运算符
        & 按位与

    优先级9, 左→右, 双目运算符
        ^ 按位异或

    优先级10, 左→右, 双目运算符
        | 按位或
*/

# define OP ~

# define MOVL <<
# define MOVR >>

# define AND &
# define XOR ^
# define OR |


// 将int数值转换为二进制的表现形式输出
void print_int2binary(int num){
   int i;
   for(i = sizeof(int)*8 - 1; i >= 0; i--){
       if((1 << i) & num)
           printf("%c", '1');
       else
           printf("%c", '0');
   }
   putchar('\n');
}


void print_multi(int num){
    puts("二进制:");
    print_int2binary(num);
    printf("八进制:\n%o\n十进制:\n%d\n十六进制:\n%x\n\n", num, num, num);
}


int main(int args, char*argv[]){
    int num1 = 19, num2 = 42,
        num_1 = -19, num_2=-42;

    print_multi(num1), print_multi(num_1);
    print_multi(num2), print_multi(num_2);

    puts("~ 取反运算");   // 0变1, 1变0
    print_multi(~num1);

    puts("<< 左移运算");   // 左移, 空位补0, 超出舍弃
    print_multi(num1<<2);
    print_multi(num_1<<2);

    puts(">> 右移运算");   // 右移, 保持符号, 空位补0, 超出舍弃
    print_multi(num1>>2);
    print_multi(num_1>>2);

    puts("& 与运算");   // 同是1返1, 两个其中之一有0, 返0
    print_multi(num1 & num2);
    print_multi(num_1 & num2);

    puts("^ 异或运算");  // 两个相异, 返1, 相同, 返0
    print_multi(num1 ^ num2);
    print_multi(num_1 ^ num2);

    puts("| 或运算");   // 两个其中之一有1, 返1, 同是0返0
    print_multi(num1 | num2);
    print_multi(num_1 | num2);
    
    return 0;
}