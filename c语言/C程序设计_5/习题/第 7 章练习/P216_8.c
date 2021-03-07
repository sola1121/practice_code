#include "stdio.h"

/*
    输入一个四位数字, 输出数字间带空格 1900 -> 1 9 0 0
*/

void insert_space(int num){
    if (num>9999 || num<1000){
        printf("Num %d out of range.", num);
    }
    int thousand=0, hundred=0, decade=0, unit=0;
    unit = num % 10;
    decade = (num-unit) % 100;
    hundred = (num-unit-decade) % 1000;
    thousand = (num-unit-decade-hundred) % 10000;
    printf("%d %d %d %d\n", thousand/1000, hundred/100, decade/10, unit);
}


void main(){
    int input = 1234;
    // printf("输入一个数: ");
    // scanf("%d", &input);
    insert_space(input);
}