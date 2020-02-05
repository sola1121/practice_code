#include "stdio.h"
#include "math.h"

int main(){
    double a, b, c, x1, x2, delta, realpart, imagpart;
    printf("����a, b, c��ֵ: ");
    scanf("%lf%lf%lf", &a, &b, &c);
    printf("����: %lfx^2 + %lfx + %lf\n", a, b, c);

    if (fabs(a)<=1e-6){
        printf("������ֵ������һ��һԪ���κ���.\n");
    } else {
        delta = b * b - 4 * a * c;
        if (fabs(delta)<=1e-6){
            printf("����������ͬ�ĸ�: %8.4f\n", -b/(2*a));
        } else if (fabs(delta>1e-6)){
            x1 = (-b+sqrt(delta))/(2*a);
            x2 = (-b-sqrt(delta))/(2*a);
            printf("��������ͬ��ʵ����: %8.4f �� %8.4f\n", x1, x2);
        } else {
            realpart = -b/(2*a);
            imagpart = sqrt(-delta)/(2*a);
            printf("���и�����: \n");
            printf("%8.4f+%8.4fi\n", realpart, imagpart);
            printf("%8.4f-%8.4fi\n", realpart, imagpart);
        }
    }

    return 0;
}
