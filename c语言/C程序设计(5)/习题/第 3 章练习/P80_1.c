#include "stdio.h"
#include "math.h"

/*
  p=(1+r)^n
*/

int main(){
    printf("�����������Ϊ7%, 10������ֵ�����������������\n");

    short n;
    double p, r;
    n = 10;
    r = 0.07;
    printf("��������: %lf", pow(1+r, n));
    getchar();
    return 0;
}
