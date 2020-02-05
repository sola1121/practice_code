#include "stdio.h"
#include "math.h"

/*
  ��1000Ԫ, ���5��
  n���ڱ�Ϣ�� P = capital * (1 + year * rate)
  ���ڱ��ں� P = capital * (1 + rate/4) ** 4*year  (1+rate/4)��һ�����ȵı�Ϣ��
*/

int main(){
    double r1 = 0.015, r2 = 0.021, r3 = 0.0275, r5 = 0.03, r = 0.0035;   // 1��, 2��, 3��, 5��, ����ÿ���Ƚ���
    double total = 1000.0, P;   // total�Ǳ���, P�Ǳ�Ϣ��
    short year;

    // 1. һ�δ�5��
    year = 5;
    P = total * (1 + year * r5);
    printf("һ�δ�5��: %lf\n", P);

    // 2. ��2��, ���ں󽫱�Ϣ�ٴ�3��
    P = total * (1 + 2 * r2);
    P = P * (1 + 3 * r3);
    printf("��2��, ���ں󽫱�Ϣ�ٴ�3��: %lf\n", P);

    // 3. ��3��, ���ں󽫱�Ϣ�ٴ�2��
    P = total * (1 + 3 * r3);
    P = P * (1 + 2 * r2);
    printf("��3��, ���ں󽫱�Ϣ�ٴ�2��: %lf\n", P);

    // 4. ��1��, ����󽫱�Ϣ�ٴ�1��, ������5��
    year = 5;
    P = total;
    while (year>0){
        P = P * (1+r1);
        year -= 1;
    };
    printf("��1��, ���ں󽫱�Ϣ�ٴ�1��, ����5��: %lf\n", P);

    // 5. �����, ÿһ������Ϣ����һ��
    year = 5;
    P = total * pow(1+r/4, 4*year);
    printf("�����, ÿһ�����Ƚ���һ��, ����5��: %lf\n", P);

    return 0;
}
