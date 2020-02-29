#include "stdio.h"
#include "time.h"
#include "stdlib.h"

#define row 3
#define column 3

/*
    二维数组中的鞍点. 在其行最大, 列最小.
*/

int main(){
    float matrix[row][column] = {0}, max_row = 0, min_column = 0, temp = 0;

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

    temp = matrix[0][0];
    max_row = matrix[0][0];
    for(int m=0; m<row; m++){
        for (int n=0; n<column; n++){
            if (temp < matrix[m][n]){
                temp = matrix[m][n];
            }
        }
        if (max_row)   // TODO: 说实话, 连思路都没有
    }


    return 0;
}