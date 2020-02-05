#include "stdio.h"
#include "math.h"

/*
  有1000元, 想存5年
  n年期本息和 P = capital * (1 + year * rate)
  活期本期和 P = capital * (1 + rate/4) ** 4*year  (1+rate/4)是一个季度的本息和
*/

int main(){
    double r1 = 0.015, r2 = 0.021, r3 = 0.0275, r5 = 0.03, r = 0.0035;   // 1年, 2年, 3年, 5年, 活期每季度结算
    double total = 1000.0, P;   // total是本金, P是本息和
    short year;

    // 1. 一次存5年
    year = 5;
    P = total * (1 + year * r5);
    printf("一次存5年: %lf\n", P);

    // 2. 先2年, 到期后将本息再存3年
    P = total * (1 + 2 * r2);
    P = P * (1 + 3 * r3);
    printf("先2年, 到期后将本息再存3年: %lf\n", P);

    // 3. 先3年, 到期后将本息再存2年
    P = total * (1 + 3 * r3);
    P = P * (1 + 2 * r2);
    printf("先3年, 到期后将本息再存2年: %lf\n", P);

    // 4. 先1年, 到其后将本息再存1年, 连续存5年
    year = 5;
    P = total;
    while (year>0){
        P = P * (1+r1);
        year -= 1;
    };
    printf("先1年, 到期后将本息再存1年, 连续5年: %lf\n", P);

    // 5. 存活期, 每一季度利息结算一次
    year = 5;
    P = total * pow(1+r/4, 4*year);
    printf("存活期, 每一个季度结算一次, 连续5年: %lf\n", P);

    return 0;
}
