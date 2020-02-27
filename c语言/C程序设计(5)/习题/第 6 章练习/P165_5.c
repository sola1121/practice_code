#include "stdio.h"

#define len 5

/*
    数组进行逆序排序
*/

int main(){
    int arr[len] = {8, 6, 5, 4, 1}, arr2[len] = {0}, a2 = 0, a1 = len-1;

    while (a1>=0){
        arr2[a2] = arr[a1];
        a2 += 1;
        a1 -= 1;
    }

    printf("排序后: ");
    for(int i=0; i<len; i++){
        printf("%d  ", arr2[i]);
    }
    printf("\n");

    return 0;
}