#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define row 3
#define column 3

/*
    注意将, 将数组作为参数传递时, 一维数组和指针是等价的, 但是二维后, 指针指向的是第0行的地址, 所以数组与指针不在等价了
    多维数组作为参数传递, 应该指明数组的维度.
*/

void transition(int matrix[row][column], int matrix_T[column][row]){
    int temp = 0;
    for (int rw=0; rw<row; rw++){
        for (int col=0; col<column; col++){
            matrix_T[rw][col] = matrix[col][rw];
        }
    }
}


void print_matrix(int matrix[row][column], char *desc){
    printf("%s 当前矩阵: \n", desc);
    for (int m=0; m<row; m++){
        for (int n=0; n<column; n++)
            printf("%5d", matrix[m][n]);
        printf("\n");
    }
}


int main(){
    srand((unsigned) time(NULL));
    int matrix[row][column] = {0}, matrix_T[column][row] = {0};

    for (int m=0; m<row; m++)
        for (int n=0; n<column; n++)
            matrix[m][n] = rand() / 10e6;
    print_matrix(matrix, "随机生成矩阵,");

    transition(matrix, matrix_T);
    print_matrix(matrix_T, "经过转置, ");

    return 0;
}