#include "stdio.h"
#include "math.h"

void main(){
    int num;
    do {
        printf("����һ��С��1000������: ");
        scanf("%d", &num);
    } while (fabs(num)>1000);

    printf("��ƽ�����ӽ�: %.0f\n", trunc(sqrt(num)));
}
