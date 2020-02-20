#include "stdio.h"
#include "math.h"

/*
    迭代法求平方根 xn+1 = 1/2(xn + a/xn)
    guess = guess-( ( (guess**2)-k ) / (2*guess) )  牛顿-拉弗森寻找平方根
*/

const double epsilon = 10e-5;

int main(){
    int num;
    double guess;
    printf("输入一个可以正数: ");
    scanf("%d", &num);
    if (num < 0) return 1;

    guess = num / 2.0;
    while (fabs(guess*guess - num)>epsilon){
        guess = guess - ((pow(guess, 2)-num) / (2*guess));
    }

    printf("推算出来的平方根为: %lf\n", guess);

    return 0;
}