#include "stdio.h"
#include "time.h"
#include "stdlib.h"

#define row 3
#define column 3

/*
    二维数组中的鞍点. 在其行最大, 列最小.

    一个二维数组最多有一个鞍点, 也可能没有.
    思路:
    先找出一行中值最大的元素, 然后检查它是否为该列中的最小值, 如果是, 则是鞍点(不需要再找别的鞍点了), 输出该鞍点
    如果不是, 再找下一行的最大数......如果每一行的最大数都不是鞍点, 则此数组无鞍点.
*/

int main(){
    int m =0 , n = 0, max_subscript = 0, flag = 0;
    float matrix[row][column] = {0}, max_row = 0.0;

    srand((unsigned) time(NULL));
    for (int m=0; m<row; m++)
        for (int n=0; n<column; n++)
            matrix[m][n] = rand() / 10e6;

    printf("当前矩阵:\n");
    for (int m=0; m<row; m++){
        for (int n=0; n<column; n++)
            printf("%.2f  ", matrix[m][n]);
        printf("\n");
    }

    // 进行检查
    for (m=0; m<row; m++){
        max_row = matrix[m][0];   // 开始时假设matrix[m][0]最大
        max_subscript = 0;   // 表示在第几列
        for (n=0; n<column; n++){     // 找出第m行中最大的数
            if (matrix[m][n] > max_row){
                max_row = matrix[m][n];
                max_subscript = n;
            }
            flag = 1;   // 先假设是鞍点, 以flag为1代表
            for (int k=0; k<row; k++)   // 将最大数和其同列元素相比
                if (max_row > matrix[k][max_subscript]){
                    flag = 0;   // 如果max_element不是同列最小, 表示不是鞍点, flag为0
                    continue;
                }
        }
        if (flag){
            printf("matrix[%d][%d]=%.2f\n", m, max_subscript, max_row);
            break;
        }
    }
    if (!flag)
        printf("It is not exist!\n");


    return 0;
}