#include "stdio.h"

#define column 2

int main(){
    // 定义数组维度, 只能使用常量或常量表达式, const变量也是变量, #define可以
    int matrix[3][column] = { 
        {1, 2}, 
        {3, 4}, 
        {5, 6}
    },
        matrix_T[column][3], m, n;

    for (m=0; m<3; m++){
        for (n=0; n<2; n++){
            matrix_T[n][m] = matrix[m][n];
        }
    }

    for (m=0; m<2; m++){
        for (n=0; n<3; n++){
            printf("%4d", matrix_T[m][n]);
        }
        printf("\n");
    }

    return 0;
}