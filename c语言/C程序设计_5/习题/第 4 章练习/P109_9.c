#include "stdio.h"
#include "math.h"

/*
  ten_thousand = num / 10000;
  thousand = (int)(num - ten_thousand * 10000) / 1000
  hundred = (int)(num - ten_thousand * 10000 - thousand * 1000) / 100
  ten = (int)(num - ten_thousand * 10000 - thousand * 1000 - hundred * 100) / 10
  indiv = (int)(num - ten_thousand * 10000 - thousand * 1000 - hundred * 100 - ten * 10)
*/

int main(){
    int num, x1, x2, x3, x4, x5, count=0;
    char *format = "%d 该数有 %d 位, 倒着来是 %d \n";
    do {
        printf("请输入5位以内正整数: ");
        scanf("%d", &num);
    } while (fabs(num)>99999);

    if (num<10){
        count += 1;
        x1 = num;
    } else if (num>=10 && num<100){
        count += 2;
        x1 = num - trunc(num / 10) * 10;   // 获得个位
        x2 = (num - x1) / 10;   // 获得十位
    } else if (num>=100 && num<1000){
        count += 3;
        x1 = num % 10;
        x2 = ((num - x1) % 100);
        x3 = ((num - x1 - x2) % 1000);
        x2 /= 10;
        x3 /= 100;
    } else if (num>=1e3 && num<1e4){
        count += 4;
        x1 = num % 10;
        x2 = ((num - x1) % 100);
        x3 = ((num - x1 - x2) % 1000);
        x4 = ((num - x1 - x2 - x3) % 10000);
        x2 /= 10;
        x3 /= 100;
        x4 /= 1000;
    } else if (num>=1e4 && num<1e5){
        count += 5;
        x1 = num % 10;
        x2 = (num - x1) % 100;
        x3 = (num - x1 - x2) % 1000;
        x4 = (num - x1 - x2 - x3) % 10000;
        x5 = (num - x1 - x2 - x3 - x4) % 100000;
        x2 /= 10;
        x3 /= 100;
        x4 /= 1000;
        x5 /= 10000;
    }

    switch (count){
    case 1:
        printf(format, num, count, x1); break;
    case 2:
        printf(format, num, count, x1*10+x2); break;
    case 3:
        printf(format, num, count, x1*100+x2*10+x3); break;
    case 4:
        printf(format, num, count, x1*1000+x2*100+x3*10+x4); break;
    case 5:
        printf(format, num, count, x1*10000+x2*1000+x3*100+x4*10+x5); break;
    }

    return 0;
}
