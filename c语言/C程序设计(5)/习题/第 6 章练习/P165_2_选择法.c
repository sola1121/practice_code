#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define len 10

/*
    使用选择法进行排列, 每一次从集合中选择一个符合一定条件的数取出
    思路: 
    设有10个元素a[1]~a[10], 将a[1]与a[2]~a[10]比较, 
    若a[1]比a[2]~a[10]都小, 则不进行交换. 
    若a[2]~a[10]中有一个以上比a[1]小, 则将其中最大的一个(假设为a[i])与a[1]交换.
    此时a[1]中存放了10个中最小的数.
    第二轮将a[2]与a[3]~a[10]比较, 将剩下9个数中的最小者a[i]与a[2]进行交换.
    此时a[2]中存放的是10个中第二小的数.
    依此类推, 共进行九轮比较, 排序完成.
*/

int main(){
    int numbers[len] = {0}, temp;
    srand((unsigned int) time(NULL));

    for (int i=0; i<len; i++){
        numbers[i] = rand()/10e6;
    }

    printf("将排列数列: ");
    for (int i=0; i<len; i++){
        printf("%d  ", numbers[i]);
    }

    // 进行选择, 并记录
    for(int m=0; m<len; m++){
        for (int n=m+1; n<len; n++){
            if (numbers[m] > numbers[n]){
                numbers[m] = temp;
                numbers[m] = numbers[n];
                numbers[n] = temp; 
            }
        }
    }

    printf("\n排列好的: ");
    for (int i=0; i<len; i++){
        printf("%d  ", numbers[i]);
    }
    printf("\n");
    return 0;
}