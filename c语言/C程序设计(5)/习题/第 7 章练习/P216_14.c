#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"

#define stu_num 10
#define grd_num 5

void print_array(float *array, int length, char *desc){
    printf("%s", desc);
    for (int i=0; i<length; i++){
        printf("%4.1f ", array[i]);
    }
}


// 每个学生的平均分
void every_students_average(float matrix[stu_num][grd_num], float container[stu_num]){
    float temp_sum=0.0;
    for (int stu=0; stu<stu_num; stu++){
        for (int grd=0; grd<grd_num; grd++){
            temp_sum += matrix[stu][grd];
        }
        container[stu] = temp_sum / stu_num;
    }
}


//每门课的平均分
void every_class_average(float matrix[stu_num][grd_num], float container[grd_num]){
    float temp_sum=0.0;
    for (int grd=0; grd<grd_num; grd++){
        for (int stu=0; stu<stu_num; stu++){
            temp_sum += matrix[stu][grd];
        }
        container[grd] = temp_sum / grd_num;
    }
}


// 最高分对应的学生与学科
void max_point(float matrix[stu_num][grd_num]){
    float max_value=0;
    int student=0, class=0;
    for (int stu=0; stu<stu_num; stu++){
        for (int grd=0; grd<grd_num; grd++){
            if (max_value<matrix[stu][grd]){
                max_value = matrix[stu][grd];
                student = stu;
                class = grd;
            }
        }
    }
    printf("\n最高分数: %.1f, 对应学号: %d, 课程: %d\n", max_value, student+1, class+1);
}


// 平均分方差
float variance(float *avg_stu, int length, int number){
    float result=0, quadratic_sum=0, sum=0;
    for (int i=0; i<length; i++){
        quadratic_sum += powf(avg_stu[i], 2.0);
        sum += avg_stu[i];
    }
    result = 1/number * quadratic_sum - powf(sum/number, 2.0);
    return result;
}


int main(){
    srand((unsigned) time(NULL));
    float students_grade[stu_num][grd_num] = {0.0};
    for (int stu=0; stu<stu_num; stu++){
        for (int grd=0; grd<grd_num; grd++)
            students_grade[stu][grd] = roundf(rand() % 1000) / 10;
    }

    for (int stu=0; stu<stu_num; stu++){
        printf("学号 %2d, 成绩 ", stu+1);
        for (int grd=0; grd<grd_num; grd++)
            printf("%4.1f ", students_grade[stu][grd]);
        printf("\n");
    }

    float average_students[stu_num];
    every_students_average(students_grade, average_students);
    print_array(average_students, stu_num, "\n每名学生的平均分: ");

    float average_classes[grd_num];
    every_class_average(students_grade, average_classes);
    print_array(average_classes, grd_num, "\n每门课的平均分:　");

    max_point(students_grade);

    printf("平均分方差: %f\n", variance(average_students, stu_num, stu_num));

    return 0;
}