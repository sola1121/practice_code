#include "stdio.h"

/*
  路程越远, 运费越低
  s<250          没有折扣
  250<=s<500     0.02
  500<=s<1000    0.05
  1000<=s<2000   0.08
  2000<=s<3000   0.1
  3000<=s        0.15
  每吨每千米货物的基本运费p(price), 货重w(weight), 距离s, 折扣d(discount), 总运费f(freight)
  f=p*w*s*(1-d)
*/

int main(){
    double p, w, s, f, temp;
    printf("依次输入基本运费,货重,距离: ");
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

    printf("应该给 %.2lf RMB.\n\n\n", f);

    // 发现其里程数都是250的倍数, 通过这个关系, 可以使用switch
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
    printf("应该给 %.2lf RMB.\n", f);

    return 0;
}
