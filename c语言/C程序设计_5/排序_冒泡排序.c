#include "stdio.h"
#include "stdlib.h"
#include "time.h"

/*
    比较相邻的元素。如果第一个比第二个大，就交换他们两个。
    对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
    针对所有的元素重复以上的步骤，除了最后一个。
    持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
    最坏时间复杂度	O ( n 2 ) 
    最优时间复杂度	O ( n ) 
*/

#define len 10

void random_array(int *arr, int length){
    srand((unsigned int) time(NULL));
    for (int i=0; i<length; i++){
        arr[i] = (int) (rand()/10e6);
    }
}


int main(){
    int arr[len] = {0}, exchanged = 1, temp = 0;
    random_array(arr, len);

    // 进行冒泡排序
    /* 
    外迴圈为排序趟数，len个数进行len-1趟,只有交换过,
    exchanged值为true才有执行迴圈的必要,否则exchanged值为false不执行迴圈 
    */
    for (int m=0; exchanged && m<len-1; m++){
        // 这里len-1也可以, 内迴圈为每趟比较的次数, 每遍循环要处理的无序部分
        for (int n=0; n<len-m-1; n++){
            exchanged = 0;
            if (arr[n]>arr[n+1]){   // 与相邻的后一个元素进行比较
                temp = arr[n];
                arr[n] = arr[n+1];
                arr[n+1] = temp;
                exchanged = 1;   // 只有数值互换过, exchanged才会从false变成true,否则数列已经排序完成,exchanged值仍然为false,没必要排序 
            }
        }
    }


    for (int i=0; i<len; i++){
        printf("%4d ", arr[i]);
    }
    printf("\n");

    return 0;
}