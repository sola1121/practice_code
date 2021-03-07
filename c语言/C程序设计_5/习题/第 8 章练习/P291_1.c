# include "stdio.h"


void sort_array(int *array, int length){
    /* 选择排序法, 将数组从小到大顺序输出 */
    int tmp;
    for (int m=0; m<length; m++){
        for (int n=m+1; n<length; n++)
            if (*(array+m) > *(array+n)){
                tmp = *(array+m);
                *(array+m) = *(array+n);
                *(array+n) = tmp;
            }
    }
}


int main(){
    const int length = 3;
    int array[length];
    for (int i=0; i<length; i++)
        scanf("%d", &array[i]);

    sort_array(array, length);

    for (int i=0; i<length; i++)
        printf("%d   ", array[i]);
    printf("\n");

    return 0;
}