# include "stdio.h"
# include "stdlib.h"
# include "time.h"

/*
    有一个班4个学生, 5们课程
    1. 求第一门课程的平均分
    2. 找出有两门以上课程不及格的学生, 输出学号, 全部课程的成绩及平均成绩
    3. 找出平均成绩在90分以上或全部课程成绩在85分以上的学生
*/

# define limit 60


void out_put(int (*pt)[5], int rw, int col){
    for (int m=0; m<rw; m++){
        printf("行%d: ", m);
        for (int n=0; n<col; n++){
            printf("%4d", *(*(pt+m)+n));
        }
        printf("\n");
    }
}


void average_first(int (*pt)[5], int rw){
    int sum=0;
    for (int i=0; i<rw; i++){
        sum += **(pt+i);
    }
    printf("\n第一门平均分: %.1f\n", ((float)sum)/rw);
}


void blow_grade(int (*pt)[5], int rw, int col){
    int count=0, sum=0;
    for (int m=0; m<rw; m++){
        count = 0;
        sum = 0;
        for (int n=0; n<col; n++){
            if (*(*(pt+m)+n) < limit) count+=1;
        }
        if (count>=2){
            printf("\n每行具有两个小于limit-%d, 行号: %d\n", limit, m);
            for (int c=0; c<col; c++) {
                printf("%4d", *(*(pt+m)+c));
                sum += *(*(pt+m)+c);
            }
            printf("   平均: %.1f\n", ((float)sum)/col);
        }
    }
}


void up_grade(int (*pt)[5], int rw, int col){
    int count=0, sum=0;
    for (int m=0; m<rw; m++){
        count = 0;
        sum = 0;
        for (int n=0; n<col; n++){
            sum += *(*(pt+m)+n);
            if (*(*(pt+m)+n) > 85) count ++;
        }
        if (sum/col > 90) {
            printf("平均分90以上的, 行号: %d\n", m);
        }
        if (count >= col) {
            printf("全部分数都在85以上的, 行号: %d\n", m);
        }
    }
}


int main(){
    srand((unsigned)time(NULL));
    int matrix[4][5], temp;
    for (int m=0; m<4; m++){
        for (int n=0; n<5; n++){
            temp = rand()%100;
            if (temp<limit) temp *=1.5;  // 将数字增幅, 让其更像分数, 可以调整来验证高分的存在
            matrix[m][n] = temp;
        }
    }

    printf("成绩矩阵:\n");
    out_put(matrix, 4, 5);

    average_first(matrix, 4);

    blow_grade(matrix, 4, 5);

    up_grade(matrix, 4, 5);

    return 0;
}