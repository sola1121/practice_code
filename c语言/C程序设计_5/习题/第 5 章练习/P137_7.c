#include "stdio.h"
#include "math.h"

void main() {
    long double result = 0.0, temp;

    temp = 0.0;
    for (int k=1; k<=100; k++){
        temp += k;
        printf("∑(100, k=%d) = %llf\n", k, temp);
        result += temp;
    }

    temp = 0.0;
    for (int k=1; k<=50; k++){
        temp += pow(k, 2);
        printf("∑(50, k=%d) = %llf\n", k, temp);
        result += temp;
    }

    temp = 0.0;
    for (int k=1; k<=10; k++){
        // 注意这里的类型, temp是0, 相加 除法得写 float/int, int/float, float/float 才能保证转换而不被精度转化造成错误
        temp = temp + 1.0/k;
        printf("∑(10, k=%d) = %llf\n", k, temp);
        result += temp;
    }

    printf("三项和: %llf\n", result);
}