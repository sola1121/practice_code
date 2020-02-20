#include "stdio.h"

/*
    冒泡排序: 将两个相邻的元素进行比较, 按大小交换顺序. 花费17次

    下面这个思路: 依此与后面的元素进行排序, 取其大放入. 花费23次
*/

int main(){
    float lst[10] = {5.1, 3.2, 2.4, 1.1, 6.8, 3.3, 9.9, 7.5, 5.1, 4.3}, temp;
    int ck, po, length = sizeof(lst)/sizeof(lst[0]), count=0;

    for (ck=0; ck<length-1; ck++){

        for (po=ck; po<length-1; po++){

            if (lst[ck]<lst[po]){
                temp = lst[ck];
                lst[ck] = lst[po];
                lst[po] = temp;
                count += 1;
            }

        }

    }


    for (int i=0; i<length-1; i++)
        printf("%4.1f ", lst[i]);

    printf("\n进行了%d 次\n", count);
    return 0;
}