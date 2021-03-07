#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define rw 3
#define col 4

// 多维数组作为形参, 这里没法使用指针了, 因为指针只与一维数组等价
float max_value(float matrix[][10], int row, int column){   // 形参中, 省略了第一维的个数参数
    float max = matrix[0][0];
    for (int m=0; m<row; m++){
        for (int n=0; n<column; n++){
            if (max<matrix[m][n])
                max = matrix[m][n];
        }
    }
    return max;
}


int main(){
    srand((unsigned) time(NULL));
    float array[rw][col] = {0};   // 这个数组可以不和函数参数中的数组大小一样, 但是其容量必须在形参容量之下
    for (int m=0; m<rw; m++){
        for (int n=0; n<col; n++){
            array[m][n] = rand() / 10e6;
        }
    }
    printf("当前的二维数组: \n");
    for (int m=0; m<rw; m++){
        for (int n; n<col; n++){
            printf("%.2f  ", array[m][n]);
        }
    }
    printf("\n");

    printf("数组中最大值: %.2f\n", max_value(array, rw, col));   // 函数的形参与实际接收到的数组维度不一样

    return 0;
}