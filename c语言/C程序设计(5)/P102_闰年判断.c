#include "stdio.h"

/*
  �ܱ�4�����Ĵ��������
  �ܱ�100���������ܱ�400��������ݲ�������
*/

int main(){
    short year, leap;
    printf("�������,�ж��Ƿ�����: ");
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
        printf("\a�����ж�, %d ������.\n", year);
        break;
    case 0:
        printf("\a�����ж�, %d ��������.\n", year);
        break;
    }

    return 0;
}
