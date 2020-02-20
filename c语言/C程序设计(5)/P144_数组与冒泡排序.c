#include "stdio.h"

// sizeof()   返回这个数组占用内存的总长度

int main(){
    float lst[10] = {5.1, 3.2, 2.4, 1.1, 6.8, 3.3, 9.9, 7.5, 5.1, 4.3}, temp;
    int ck, po, length = sizeof(lst)/sizeof(lst[0]), count = 0;

    for (ck=0; ck<length-1; ck++){
        for (po=0; po<length-1-ck; po++){
            if (lst[po] > lst[po+1]){
                temp = lst[po];
                lst[po] = lst[po+1];
                lst[po+1] = temp;
                count += 1;
            }
        }
    }

    for (int i=0; i<length; i++)
        printf("%4.1f", lst[i]);

    printf("\n进行了%d 次.\n ", count);
    return 0;
}