#include "stdio.h"
#include "string.h"

/*
  求最小和最大公约数
*/

unsigned int divisor(unsigned int num, char *flag){
    if (strcmp(flag, "max")!=0 && strcmp(flag, "min")!=0)
        return 0;
    // 为了之后在循环中可以通过与i比对从而赋大小, 这一步很重要
    unsigned int result = strcmp(flag, "max")==0 ? 2: num/2;   // 求max就给初始值2, 求min就给初始值num/2
    for (unsigned int i=2; i<=num/2; i++){
        if (num % i == 0){
            switch (strcmp(flag, "max")){
            case 0:    // max
                result = result<i? i: result;
                break;
            default:   // min
                result = result>i? i: result;
                break;
            }
        }
    }
    if (result == num)
        return 0;
    return result;
}


int main(){
    char *input_format = "输入一个正整数: ",
         *output_format = "%d 's 最小公约数: %d, 最大公约数: %d\n";
    unsigned int m, n;
    printf("%s", input_format);
    scanf("%d", &m);
    printf("%s", input_format);
    scanf("%d", &n);

    printf(output_format, m, divisor(m, "min"), divisor(m, "max"));
    printf(output_format, n, divisor(n, "min"), divisor(n, "max"));

    return 0;
}