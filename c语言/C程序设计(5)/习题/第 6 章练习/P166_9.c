#include "stdio.h"
#include "time.h"
#include "stdlib.h"

#define len 15

/*
    15个数按由大到小排列放在一个数组中
    输入一个数, 使用二分法找出其是数组中第几个元素, 不在输出提示
*/

int main(){
    int arr[len] = {0}, low=0, high=len, sub = (low + high) / 2, temp = 0;

    srand((unsigned) time(NULL));
    for (int i=0; i<len; i++)
        arr[i] = (int) (rand() / 10e6);
    
    for (int m=0; m<len-1; m++){   // FIXME: 这个冒泡没有工作
        if (arr[m] < arr[m+1]){
            temp = arr[m];
            arr[m] = arr[m+1];
            arr[m+1] = temp;
        }
    }


    printf("当前数组: ");
    for (int i=0; i<len; i++)
        printf("%4d ", arr[i]);
    printf("\n");

    // TODO: 该二分法找下标了


    return 0;
}