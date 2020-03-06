#include "stdio.h"

#define len 11

/*
    log2(n) 为最大查询
*/

int main(){
    unsigned int n = 0;
    int arr[len] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},   // 用于具有一定顺序的元素
          low=0, high=len, input;

    printf("输入一个数: ");
    scanf("%d", &input);

    n = (low + high)/2;
    while ((arr[n] != input) && low<high){
        if (input<arr[0] || input>arr[len-1]){   // 判断是否在需要判断的范围内
            n = len + 1;
            break;
        }

        if (arr[n] < input){
            low = n;
        } else if (arr[n] > input) {
            high = n;
        } else {
            break;
        }
        n = (low + high)/2;
    }

    printf("在下标 %d\n", n);


    return 0;
}