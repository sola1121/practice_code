#include "stdio.h"

/*
  1! + 2! + 3! + ... + 20!
*/

#define limit 20

int main(){
    unsigned long long temp, result = 0;

    for (unsigned long long i=1; i<=limit; i++){
        temp = 1;   // 重置
        for (unsigned long long v=1; v<=i; v++){
            printf("%lld", v);
            if (v != i) printf("*");
            temp *= v;
        }
        if (i != limit) printf("+");
        result += temp;
    }

    printf("=%lld\n", result);
    return 0;
}