#include "stdio.h"

/*
    求n!

    record 1: 1
    record 2: 2
    record 3: 6
    record 4: 24
    record 5: 120
    5! = 120

    每次调用fac函数后, 其返回值record应返回到调用fac函数处.
    当n==1时, 终止record继续调用fac
*/

unsigned long long fac(unsigned long long);

unsigned long long main(){
    unsigned long long n=19, y;

    printf("%lld! = %lld\n", n, fac(n));

    return 0;
}


unsigned long long fac(unsigned long long n){
    unsigned long long record;
    if (n < 0){
        printf("n<0, data error.\n");
    } else if (n == 0 || n == 1) {
        record = 1;
    } else {
        record = fac(n-1) * n;   // n>1时, 调用自身 n! = n*(n-1)
    }

    printf("record %lld: %lld\n", n, record);
    return record;
}