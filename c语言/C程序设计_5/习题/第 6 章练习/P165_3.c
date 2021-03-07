#include "stdio.h"


int main(){
    float matrix[3][3] = {
        {5.12, 4.26, 3.14},
        {9.8,  7.65, 4.3 },
        {5.7,  8.0,  3.64}
    },
    sum = 0;

    for (int m=0; m<3; m++){
        for (int n=0; n<3; n++){
            if (m=n)
                sum += matrix[m][n];
        }
    }

    printf("该矩阵对角和: %f\n", sum);

    return 0;
}