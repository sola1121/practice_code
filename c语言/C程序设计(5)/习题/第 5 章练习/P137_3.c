#include "stdio.h"
#include "string.h"

/*
  求最小和最大公约数
*/

unsigned int divisor(unsigned int num, char *flag){
    if (!strcmp(flag, "min") || !strcmp(flag, "min")  )
        return 0;
    unsigned int result = 0;
    for (unsigned int i=2; i<=num/2; i++){
        if (num % i == 0){
            switch (strcmp(flag, "max")){
            case 0:         // max
                // result = result<i ? i: result; 
                // printf("此时的result %d\n", result);
                if (result<i) result = i;
                break;
            default:        // min
                // result = result>i ? i: result;
                // printf("此时的result %d\n", result);
                if (result>i) result = i;
                break;
            }
        }
    }
    return result;
}


int main(){
    char *input_format = "输入一个正整数:",
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