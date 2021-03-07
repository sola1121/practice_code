# include "stdio.h"

# define len 10


void input_number(float *pt, int length){
     for (int i=0; i<length; i++)
        scanf("%f", pt+i);
}


void output_number(float *pt, int length){
    for (int i=0; i<length; i++)
        printf("%.2f  ", *(pt+i));
    printf("\n");
}


void handle(float *pt, int length){
    // 将数组中最小的数与第一个数对换, 最大的数与最后一个数对换
    float temp = 0;
    int index_min = 0, index_max = 0;
    for (int i=0; i<length; i++){
        if (*(pt+index_min) > *(pt+i)) index_min = i;
        if (*(pt+index_max) < *(pt+i)) index_max = i;
    }

    // 数组第一位与最小的那一位交换
    temp = *(pt+0);
    *(pt+0) = *(pt+index_min);
    *(pt+index_min) = temp;

    // 数组最后一位与最大的那一位交换
    temp = *(pt-1+length);
    *(pt-1+length) = *(pt+index_max);
    *(pt+index_max) = temp;
}


int main(){
    float array[len];

    input_number(array, len);

    handle(array, len);

    output_number(array, len);

    return 0;
}