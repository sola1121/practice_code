#include "stdio.h"
#include "math.h"

/*
    牛顿-拉弗森 法, x进一步精确值 = x - f(x)/f导(x)

    求 ax**3 + bx**2 + cx + d = 0, 在1处的解
*/
#define limit 10e6


double solve(double a, double b, double c, double d){
    int count = 0;
    double result = 5,   // 随意给了个初始值
           func = 0.0, func_derivative = 0.0;
    while (fabs(result - 1) > 10e-4){
        func = a*pow(result, 3) + b*pow(result, 2) + c*result + d;
        func_derivative = 3*a*pow(result, 2) + 2*b*result + c;
        result = result - func/func_derivative;
        if (count>limit) break;
        count += 1;
    }
    return result;
}


int main(){
    printf("ax**3 + bx**2 + cx + d = 0, 在1处的接近解: %lf\n", solve(1.0, 2.0, 3.0, 4.0));

    return 0;
}