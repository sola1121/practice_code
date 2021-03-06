# include "stdio.h"

/*
要获取具体某一个位置的元素, 当前行数*总列数+当前列数

*/


int main(){

    int arr[4][3] = {11, 12, 13, 21, 22, 23, 31, 32, 33, 41, 42, 43};


    // 通过指针遍历二维数组

    /*
        p使用int *p;定义, 它是指向整形数据的, p+1所指向的元素是p所指向的列元素的下一个元素
    */

    int *p;   // int指针变量
    printf("一个int元素的字节 %ld\n", sizeof(arr[0][0]));
    for(p=arr[0]; p<arr[0]+12; p++){   // 使p一次指向下一个元素, 总共执行12次
        if ((p-arr[0])%3==0)   // p移动三次后换行
            printf("\n");
        printf("%3d", *p);
    }

    printf("\n");

    printf("获取具体某一个位置的元素, 如1行1列, arr[1][1]=%d\n", *(arr+1*3+1));


    // 通过指定一个数组指针, 让指针可以直接引用arr[0], 这样就可以通过该指针一行一行的遍历

    /*
        p指向一个包含m个元素的一维数组. 这时以, 如果p先指向arr[0](即p=&arr[0]), 则p+1不是指向arr[0][1], 
        而是指向arr[1], p的增值以一维数组的长度为单位.
    */

    int (*pt)[3], i, j;   // (*p)[3]可以容纳三个int元素的int指针
    pt = arr;   // pt指向二维数组的第0行
    printf("输入行和列: ");
    scanf("%d,%d", &i, &j);
    printf("a[%d][%d]=%d\n", i, j, *(*(pt+i)+j));   // pt+i 获得对应的行地址, *(pt+i)获得指向行的数组地址, *(pt+i)+j获得具体元素的位置地址, *(*(pt+i)+j)获得具体元素

    return 0;
}