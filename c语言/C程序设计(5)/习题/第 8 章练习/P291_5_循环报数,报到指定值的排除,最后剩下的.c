# include "stdio.h"

/* 
    n个人围成一圈, 顺序排号. 从第1个人开始报数(从1到3报数), 
    凡是报到3的人退出圈子, 最后留下的是原来第几号的人.
*/

# define len 50


int main(){
    int *pt, array[len], i, k, m, n;
    for (i=0; i<len; i++)
        array[i] = i+1;

    n = len;
    pt = array;
    for (i=0; i<n; i++)
        *(pt+i) = i + 1;   // 以1至n为序给每个人编号

    i = 0;   // i为每次循环时计数变量
    k = 0;   // k为按1, 2, 3报数时的计数变量
    m = 0;   // m为退出人数

    while (m<n-1){   // 当退出人数比n-1少时(即未退出人数大于1时)执行循环体
        if (*(pt+i)!=0) k++;
        if (k==3){
            *(pt+i) = 0;   // 对退出的人的编号置为0
            k = 0;
            m++;
        }
        i++;
        if (i==n) i=0;   // 报数到尾后, i恢复为0
    }

    while(*pt==0) pt++;
    printf("最后剩下的是位置: %d\n", *pt);
    
    return 0;
}