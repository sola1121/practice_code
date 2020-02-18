#include "stdio.h"
#include "math.h"

/*
  三位数中的水仙花数 153 = 1**3 + 5**3 + 3**3
*/

const unsigned int start_limit = 100;
const unsigned int end_limit = 1000;

int main(){
    unsigned int digit, ten_digit, hundred;
    printf("输出三位数 %d ~ %d 的水仙花数\n", start_limit, end_limit);
    for (unsigned int i=start_limit; i<end_limit; i++){
        hundred = i / 100;
        ten_digit = (i - hundred * 100) / 10;
        digit = (i - hundred * 100 - ten_digit * 10);
        if (i == pow(hundred, 3) + pow(ten_digit, 3) + pow(digit, 3))
            printf("%5d", i);
    }

    printf("\n");
    return 0;
}