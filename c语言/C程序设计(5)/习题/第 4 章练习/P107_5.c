#include "stdio.h"
#include "math.h"

void main(){
    int num;
    do {
        printf("输入一个小于1000的正数: ");
        scanf("%d", &num);
    } while (fabs(num)>1000);

    printf("其平方根接近: %.0f\n", trunc(sqrt(num)));
}
