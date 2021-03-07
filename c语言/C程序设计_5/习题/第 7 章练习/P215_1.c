#include "stdio.h"

/*
    都是使用例举法来求
*/

int Greatest_Common_Divisor(int a, int b){
    // 最大公约数
    int result = 0, the_min = a<b?a:b;
    for (int factor=2; factor<=the_min; factor++){
        if (a%factor==0 && b%factor==0){
            result = factor;
        }
    }
    return result;
}


int Least_Common_Multiple(int a, int b){
    // 最小公倍数
    int result = 0, the_max = a>b?a:b;
    for (int multiple=the_max+1; ; multiple++){
        if (multiple%a==0 && multiple%b==0){
            result = multiple;
            break;
        }
    }
    return result;
}


int main(){
    int input_a = 0, input_b = 0, divisor = 0, multiple = 0;

    printf("输入两个数: ");
    scanf("%d %d", &input_a, &input_b);
    
    divisor = Greatest_Common_Divisor(input_a, input_b);
    multiple = Least_Common_Multiple(input_a, input_b);

    printf("最大公约数: %d, 最小公倍数: %d\n", divisor, multiple);
    return 0;
}