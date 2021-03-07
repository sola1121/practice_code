#include <stdio.h>
#include <math.h>
/*
y=ax^2 + bx +c

x=(-b)土sqrt(b^2-4*a*c)
delta = b^2 - 4*a*c


printf 与 scanf 函数由stdio.h库提供, 并不是C的关键字

*/

int main(){
    double a, b, c, disc, x1, x2, p, q;
    scanf("%lf%lf%lf", &a, &b, &c);   // 要求输入双精度型变量
    disc = b*b - 4 * a *c;
    if (disc<0){
        printf("There is no answer.");
        return 0;
    }
    p = -b/(2.0 * a);
    q = sqrt(disc)/(2.0 * a);
    x1 = p + q; x2 = p - q;
    printf("x1=%7.2f\nx2=%7.2f\n", x1, x2);
    return 0;
}
