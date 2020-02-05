#include "stdio.h"

/*
  ·��ԽԶ, �˷�Խ��
  s<250          û���ۿ�
  250<=s<500     0.02
  500<=s<1000    0.05
  1000<=s<2000   0.08
  2000<=s<3000   0.1
  3000<=s        0.15
  ÿ��ÿǧ�׻���Ļ����˷�p(price), ����w(weight), ����s, �ۿ�d(discount), ���˷�f(freight)
  f=p*w*s*(1-d)
*/

int main(){
    double p, w, s, f, temp;
    printf("������������˷�,����,����: ");
    scanf("%lf%lf%lf", &p, &w, &s);

    if (s<250){
        f = p * w * s;
    } else if (s>=250 && s<500){
        f = p * w * s * (1-0.02);
    } else if (s>=500 && s<1000){
        f = p * w * s * (1-0.05);
    } else if (s>=1000 && s<2000){
        f = p * w * s * (1-0.08);
    } else if (s>=2000 && s<3000){
        f = p * w * s * (1-0.1);
    } else if (s>=3000){
        f = p * w * s * (1-0.15);
    }

    printf("Ӧ�ø� %.2lf RMB.\n\n\n", f);

    // ���������������250�ı���, ͨ�������ϵ, ����ʹ��switch
    int count;
    double d;
    count = s / 250;
    switch(count){
    case 0:
        d = 0;
        break;
    case 1:
        d = 0.02;
        break;
    case 2:
    case 3:
        d = 0.05;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        d = 0.08;
        break;
    case 8:
    case 9:
    case 10:
    case 11:
        d = 0.1;
        break;
    case 12:
        d = 0.15;
        break;
    }

    f = p * w * s * (1-d);
    printf("Ӧ�ø� %.2lf RMB.\n", f);

    return 0;
}
