#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define len 10

// 函数传参是值传递

// 传入值
float max_of_tow(float num1, float num2){
    return num1>num2 ? num1 : num2;
}

// 传入指针值, 注意要是传入是数组, 应该写明长度arr[10], 因为这已经算一个新类型了
float average(float *array, int length){   // 如果要传入数组, 形参应该是 (float array[10], int length)
    float sum = 0;
    for (int i=0; i<length; i++){
        sum += array[i];
    }
    return sum/length;
}

int main(){
    srand((unsigned) time(NULL));
    float array[len] = {0};
    for (int i=0; i<len; i++){
        array[i] = rand() / 10e6;
    }
    printf("当前数组:\n");
    for (int i=0; i<len; i++){
        printf("%.2f  ", array[i]);
    }
    printf("\n");

    // 使用max函数求二者之间最大值
    float the_max = array[0];
    for (int i=1; i<len; i++){
        the_max = max_of_tow(the_max, array[i]);   // 传入数组的元素值
    }
    printf("最大的值是%.2f\n", the_max);

    // 使用average函数求数组平均值
    printf("平均值是:%.2f\n", average(array, len));   // 传入指针值, 数组的地址

    return 0;
}