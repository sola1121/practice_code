# include "stdio.h"
# include "stdlib.h"
# include "time.h"

/*
    将一个5×5的矩阵中最大的元素与在中心的元素进行交换, 即把最大值的元素放在中心
    4角分别交换为4个最小的元素(顺序为从左到右, 从上到下一次存放)
*/

# define row 5
# define column 5


void sort_array(float *array, int length){
    // 用于从小到大排列数组
    float temp=0;
    for (int m=0; m<length; m++){
        for (int n=m+1; n<length; n++){
            if (*(array+m)>*(array+n)){
                temp = *(array+n);
                *(array+n) = *(array+m);
                *(array+m) = temp;
            }
        }
    }
}


void out_put(float (*matrix)[5], int rw, int col){
    // 用于输出矩阵
    for (int m=0; m<rw; m++){
        for (int n=0; n<col; n++){
            printf("%8.2f", *(*(matrix+m)+n));
        }
        printf("\n");
    }
}


void handle_matrix(float (*matrix)[5], int rw, int col){
    // TODO:
    float max = *(*(matrix+0)+0), 
          min_array[4] = {*(*(matrix+0)+0),*(*(matrix+0)+0),*(*(matrix+0)+0),*(*(matrix+0)+0)};
    int count = 0;   // 用于记录最小数组中这是第几个最小的
    for (int m=0; m<rw; m++){
        for (int n=0; n<col; n++){
            if (max<*(*(matrix+m)+n)) max = *(*(matrix+m)+n);
            // TODO: 分别从最小到第四小开始找, 要注意排除已经找到的值
        }
    }
    sort_array(min_array, 4);
    printf("最大值: %.2f\n", max);
    printf("最小值数组: ");
    for (int i=0; i<4; i++)
        printf("%8.2f", *(min_array+i));
    // 将最大元素放在中间
    // 将小元素排列到四个角
}


int main(){
    float matrix[row][column];

    // 随机生成矩阵
    srand((unsigned)time(NULL));
    for (int rw=0; rw<row; rw++){
        for (int col=0; col<column; col++){
            matrix[rw][col] = rand()/10e6;
        }
    }

    out_put(matrix, row, column);

    handle_matrix(matrix, row, column);

    return 0;
}