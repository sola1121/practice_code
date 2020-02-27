#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define len 10

/*
    使用选择法进行排列, 每一次从集合中选择一个符合一定条件的数取出
*/

int main(){
    int numbers[len] = {0}, sorted_numbers[len] = {0}, temp;
    srand((unsigned int) time(NULL));

    for (int i=0; i<len; i++){
        numbers[i] = rand()/10e6;
    }

    printf("将排列数列: ");
    for (int i=0; i<len; i++){
        printf("%d  ", numbers[i]);
    }

    // 进行选择, 并记录
    
    /* 摸了 */

    printf("\n排列好的: ");
    for (int i=0; i<len; i++){
        printf("%d  ", sorted_numbers[i]);
    }
    printf("\n");
    return 0;
}