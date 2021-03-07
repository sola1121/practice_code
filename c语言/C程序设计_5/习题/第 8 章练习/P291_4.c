# include "stdio.h"
# include "stdlib.h"
# include "time.h"

# define len 8
# define move 3


int main(){
    int array[len];

    srand((unsigned) time(NULL));
    for (int i=0; i<len; i++)
        *(array+i) = (int) (rand()/10e6);

    printf("原始数组: \n");
    for (int i=0; i<len; i++)
        printf("%d  ", *(array+i));
    printf("\n");

    // 让数组后面的move个元素移动到数组开头
    char * temp1[len-move], * temp2[move];
    // 复制原先开头部分
    for (int m=0; m<len-move; m++)
        * (temp1+m) = * (array+m);
    // 复制原先后端部分
    for (int m=0, n=len-move; m<move; m++, n++)
        * (temp2+m) = * (array+n);
    // 后端部分+开头部分
    for (int i=0; i<move; i++)
        *(array+i) = *(temp2+i);
    for (int i=len-move, m=0; i<len; i++, m++)
        *(array+i) = *(temp1+m);

    printf("处理后后数组: \n");
    for (int i=0; i<len; i++)
        printf("%d  ", *(array+i));
    printf("\n");

    return 0;
}