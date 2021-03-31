# include "stdio.h"

/*  
    使用0
    0000000000000000
  ~
    1111111111111111
  <<6
    1111111111000000
然后再同要运算的数相 &与, 就可把其前多少位取出

同理, 要取从右端开始的, 只需将 ~0 右移
*/

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


int main(int args, char * argv[]){
    int num = 0;

    printf("输入一个数: ");
    scanf("%d", &num);
    puts("将会取其右开始的21位.");

    int zero = ~0;
    zero <<= (sizeof(int)*8 - 21);

    print_int2binary(num);
    print_int2binary(zero);

    num &= zero;

    print_int2binary(num);

    return 0;
}