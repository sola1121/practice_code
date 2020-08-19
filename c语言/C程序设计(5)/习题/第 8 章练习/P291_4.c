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

    // TODO: 让数组后面的move个元素移动到数组开头
    int temp1[move], temp2[len-move];
    for (int m=len-move-1, n=0; n<move; m++ ,n++)
        temp1[n] = array[m];
    for (int m=0, n=0; n<move; m++, n++)
        temp2[n] = array[m];
    for (int i=0; i<len-move-1; i++)
        array[i] = temp2[i];
    for (int m=len-move-1, n=0; m<len; m++, n++)
        array[m] = temp1[n];

    printf("处理后后数组: \n");
    for (int i=0; i<len; i++)
        printf("%d  ", *(array+i));
    printf("\n");

    return 0;
}