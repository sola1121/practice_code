#include "stdio.h"
#include "math.h"

/*
  p=(1+r)^n
*/

int main(){
    printf("如果年增长率为7%, 10年后的总值与现在相比增长多少\n");

    short n;
    double p, r;
    n = 10;
    r = 0.07;
    printf("将会增长: %lf", pow(1+r, n));
    getchar();
    return 0;
}
