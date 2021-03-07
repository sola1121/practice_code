# include "stdio.h"
# include "string.h"

/*
    指向结构体对象的指针变量即可指向结构体变量, 也可指向结构体数组中的元素. 
    指针变量的基类型必须与结构体变量的类型相同.
*/


int main(){
    struct Student{
        long ID;
        char name[32];
        unsigned short gender;
        float score;
    };

    struct Student stu_1;
    struct Student *p_stu;   // 指向struct Student类型数据的指针变量

    p_stu = &stu_1;  // 将p_stu指向stu_1, 注意这里使用的是&stu_1

    stu_1.ID = 3141592653;
    strcpy(stu_1.name, "stu_1变量");   // 用字符串复制函数给stu_1.name赋值
    stu_1.gender = 1;
    stu_1.score = 87;

    printf("使用stu_1来输出值 %ld, %s, %s, %.1f\n", \
            stu_1.ID, stu_1.name, stu_1.gender==0?"female":"male", stu_1.score);

    printf("使用(*p_stu). 输出值 %ld, %s, %s, %.1f\n", \
            (*p_stu).ID, (*p_stu).name, (*p_stu).gender==0?"female":"male", (*p_stu).score);

    printf("使用p_stu -> 输出值 %ld, %s, %s, %.1f\n", \
            p_stu->ID, p_stu->name, p_stu->gender==0?"female":"male", p_stu->score);

    return 0;
}