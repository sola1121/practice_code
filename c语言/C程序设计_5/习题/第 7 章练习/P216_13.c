#include "stdio.h"

/*
    勒让德多项式公式
    pn(x)
    n=0, pn(x) = 1
    n=1, pn(x) = x
    n>1, pn(x) = ( (2n-1)*x - pn-1(x) - (n-1)*pn-2(x) ) / n
*/


double polya(double x, int n){
    if (n==0)
        return 1.0;
    else if (n==1)
        return x;
    else {
        return ((2.0*n - 1.0) * x * polya(n-1.0, x) - (n-1.0) * polya(n-2.0, x)) / n;
    }
}


int main(){
    int n = 11;
    double x = 3;

    printf("%lf\n", polya(x, n));

    return 0;
}