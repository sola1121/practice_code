#include <stdio.h>
#include <math.h>
/*
y=ax^2 + bx +c

x=(-b)��sqrt(b^2-4*a*c)
delta = b^2 - 4*a*c


printf �� scanf ������stdio.h���ṩ, ������C�Ĺؼ���

*/

int main(){
    double a, b, c, disc, x1, x2, p, q;
    scanf("%lf%lf%lf", &a, &b, &c);   // Ҫ������˫�����ͱ���
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
