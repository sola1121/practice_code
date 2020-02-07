#include "stdio.h"
#include "math.h"

int main(){
    double a, b, c, x1, x2, delta, realpart, imagpart;
    printf("输入a, b, c的值: ");
    scanf("%lf%lf%lf", &a, &b, &c);
    printf("计算: %lfx^2 + %lfx + %lf\n", a, b, c);

    if (fabs(a)<=1e-6){
        printf("所给数值构不成一个一元二次函数.\n");
    } else {
        delta = b * b - 4 * a * c;
        if (fabs(delta)<=1e-6){
            printf("具有两个相同的根: %8.4f\n", -b/(2*a));
        } else if (fabs(delta>1e-6)){
            x1 = (-b+sqrt(delta))/(2*a);
            x2 = (-b-sqrt(delta))/(2*a);
            printf("有两个不同的实数根: %8.4f 和 %8.4f\n", x1, x2);
        } else {
            realpart = -b/(2*a);
            imagpart = sqrt(-delta)/(2*a);
            printf("具有复数根: \n");
            printf("%8.4f+%8.4fi\n", realpart, imagpart);
            printf("%8.4f-%8.4fi\n", realpart, imagpart);
        }
    }

    return 0;
}
