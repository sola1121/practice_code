# include "stdio.h"

# define row 3
# define column 3


void out_put(int (*pt)[3], int rw, int col){
    for (int m=0; m<rw; m++){
        for(int n=0; n<col; n++){
            printf("%5d", *(*(pt+m)+n));
        }
        printf("\n");
    }
}


void transform(int (*pt)[3], int (*pt_T)[3]){
    int rw=0, col=0;
    for (; rw<row; rw++){
        for (; col<column; col++){
            *(*(pt_T+col)+rw) = *(*(pt+rw)+col);
        }
    }
}



int main(){
    int matrix[row][column] = {11, 12, 13, 21, 22, 23, 31, 32, 33}, 
        matrix_T[column][row];

    printf("矩阵:\n");
    out_put(matrix, row, column);

    for (int m=0; m<row; m++){
        for (int n=0; n<row; n++){
            *(*(matrix_T+n)+m) = *(*(matrix+m)+n);
        }
    }
    // 执行转至
    transform(matrix, matrix_T);


    printf("转置矩阵:\n");
    out_put(matrix_T, column, row);

    return 0;
}