#include "stdio.h"

/*
    冒泡排序: 将两个相邻的元素进行比较, 按大小交换顺序. 花费17次

    下面这个思路: 依此与后面的元素进行排序, 取其大放入. 花费23次
*/

void bubble_sort(int a[],int n)//n为数组a的元素个数
{
    // 一定进行N-1轮比较
    for(int i=0; i<n-1; i++) {
        // 每一轮比较前n-1-i个, 即已排序好的最后i个不用比较
        for(int j=0; j<n-1-i; j++) {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int main(){
    float lst[10] = {5.1, 3.2, 2.4, 1.1, 6.8, 3.3, 9.9, 7.5, 5.1, 4.3}, temp;
    int ck, po, length = sizeof(lst)/sizeof(lst[0]), count=0;

    // 选择排序 (￣┰￣*)
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