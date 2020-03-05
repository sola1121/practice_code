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
    
    // 冒泡排序
    for (int m=0; m<len-1; m++){
        for (int n=0; n<len-m-1; n++){
            if (arr[n] > arr[n+1]){
                temp = arr[n];
                arr[n] = arr[n+1];
                arr[n+1] = temp;
            }
        }
    }

    printf("当前数组: ");
    for (int i=0; i<len; i++)
        printf("%4d ", arr[i]);
    printf("\n");

    printf("要查询的数: ");
    scanf("%d", &temp);
    if (temp>arr[len-1] || temp<arr[0]){
        printf("所输入超出范围.");
        return 0;
    }

    // 二分法找下标
    while (low!=high){
        if (arr[sub] < temp){
            low = sub;
        } else if (arr[sub] > temp){
            high = sub;
        } else {
            break;
        }
        sub = (low+high)/2;
    }

    printf("所要找的下标: %d\n", sub);

    return 0;
}