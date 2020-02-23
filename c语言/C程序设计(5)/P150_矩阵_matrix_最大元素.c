#include "stdio.h"
#include "stdlib.h"
#include "time.h"


#define row 3
#define column 4


int main(){
    float matrix[row][column] = {{0.0, 0.0}};

    srand((unsigned)time(NULL));
    for (int rw=0; rw<row; rw++){
        for (int col=0; col<column; col++){
            matrix[rw][col] = rand()/10e6;
        }
    }

    printf("当前矩阵:\n");
    for (int rw=0; rw<row; rw++){

        for (int col=0; col<column; col++){
            printf("%5.2f  ", matrix[rw][col]);
        }
        printf("\n");
    }

    float max_value = matrix[0][0];
    for (int rw=0; rw<row; rw++){
        for (int col=0; col<column; col++){
            if (matrix[rw][col] > max_value)
                max_value = matrix[rw][col];
        }
    }

    printf("\n最大值是: %.2f\n", max_value);

    return 0;
}