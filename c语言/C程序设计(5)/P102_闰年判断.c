#include "stdio.h"

/*
  能被4整除的大多是闰年
  能被100整除而不能被400整除的年份不是闰年
*/

int main(){
    short year, leap;
    printf("输入年份,判断是否闰年: ");
    scanf("%d", &year);

    if (year%4==0){
        if (year%100==0){
            if (year%400==0){
                leap = 1;
            } else {
                leap = 0;
            }
        } else {
            leap = 0;
        }
    } else {
        leap = 0;
    }

    /*
    if ((year%4==0 && year%100!=0) || (year%400==0))
        leap = 1;
    else
        leap = 0;
    */

    switch (leap){
    case 1:
        printf("\a经过判断, %d 是闰年.\n", year);
        break;
    case 0:
        printf("\a经过判断, %d 不是闰年.\n", year);
        break;
    }

    return 0;
}
