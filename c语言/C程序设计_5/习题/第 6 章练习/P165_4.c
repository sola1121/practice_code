#include "stdio.h"

#define len 16

/*
    一个已经排序好的数列, 输入一个值, 排列进去
*/

int main(){
    int insert_point = 0;
    float nums[len] = {1.0, 2.3, 4.5, 5.1, 5.2, 6.3, 7.8, 9.9, 9.9, 10.0}, 
          input_num = 0.0;

    printf("当前: ");
    for (int i=0; i<len; i++){
        printf("%.2f  ", nums[i]);
    }

    printf("\n输入一个数: \n");
    scanf("%f", &input_num);

    // 获取插入点
    for (int i=0; i<len; i++){
        if (input_num <= nums[i]){
            insert_point = i;
            break;
        }
    }
    printf("插入点下标: %d\n", insert_point);

    // 进行插入, 这里使用的是倒着插入
    for (int i = len; i>=insert_point; i--){
        if (i == insert_point)
            nums[i] = input_num;
        else
            nums[i] = nums[i-1];
    }

    printf("\n插入后: ");
    for (int i=0; i<len; i++){
        printf("%.2f  ", nums[i]);
    }
    printf("\n");

    return 0;
}