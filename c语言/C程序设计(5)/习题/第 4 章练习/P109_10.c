#include "stdio.h"

int main(){
    double result = 0, w;
    printf("输入利润: ");
    scanf("%lf", &w);

    // if
    if (w <= 1e5){
        result += w * 0.1;
    }
    if (w>1e5 && w<=2e5){
        result += 1e5 * 0.1;
        result += (w-1e5) * 0.075;
    }
    if (w>2e5 && w<=4e5){
        result += 1e5 * 0.1;
        result += (2e5-1e5) * 0.075;
        result += (w-2e5) * 0.05;
    }
    if (w>4e5 && w<=6e5){
        result += 1e5 * 0.1;
        result += (2e5-1e5) * 0.075;
        result += (4e5-2e5) * 0.05;
        result += (w-4e5) * 0.03;
    }
    if (w>6e5 && w<1e6){
        result += 1e5 * 0.1;
        result += (2e5-1e5) * 0.075;
        result += (4e5-2e5) * 0.05;
        result += (6e5-4e5) * 0.03;
        result += (w-6e5) * 0.015;
    }
    if (w>1e6){
        result += 1e5 * 0.1;
        result += (2e5-1e5) * 0.075;
        result += (4e5-2e5) * 0.05;
        result += (6e5-4e5) * 0.03;
        result += (1e6-6e5) * 0.015;
        result += (w-1e6) * 0.01;
    }

    printf("\n应该发奖金: %.2lf \n", result);

    // switch
    result = 0;
    int flag;
    if (w>1e6)
        flag = 10;
    else
        flag = (int)w / 1e5;   // 求最高位, 就是万位

    switch(flag){
    case 0:
    case 1:
        result += w * 0.1;
        break;
    case 2:
    case 3:
        result += 1e5 * 0.1;
        result += (2e5-1e5) * 0.075;
        result += (w-2e5) * 0.05;
        break;
    case 4:
    case 5:
        result += 1e5 * 0.1;
        result += (2e5-1e5) * 0.075;
        result += (4e5-2e5) * 0.05;
        result += (w-4e5) * 0.03;
        break;
    case 6:
    case 7:
    case 8:
    case 9:
        result += 1e5 * 0.1;
        result += (2e5-1e5) * 0.075;
        result += (4e5-2e5) * 0.05;
        result += (6e5-4e5) * 0.03;
        result += (w-6e5) * 0.015;
        break;
    case 10:
        result += 1e5 * 0.1;
        result += (2e5-1e5) * 0.075;
        result += (4e5-2e5) * 0.05;
        result += (6e5-4e5) * 0.03;
        result += (1e6-6e5) * 0.015;
        result += (w-1e6) * 0.01;
        break;
    }

    printf("应该发奖金: %.2lf \n", result);

    return 0;
}
