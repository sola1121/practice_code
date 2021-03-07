# include "stdio.h"
# include "string.h"

/*
    将一个结构体传递给函数, 有3个方法
    1. 用结构体变量的成员做参数, 形参就需要写为对应的类型就可. 使用值传递.
    2. 用结构体变量做参数, 形参写为对应的结构体类型. 使用值传递, 在结构体较为庞大的时候, 资源消耗较多.
    3. 用指向结构体变量(或数组元素)的指针做实参, 将结构体变量(或数组元素)的地址传给形参. 发生更改会影响原变量.
*/

# define len 5

struct Student {
    unsigned long ID;
    char name[32];
    unsigned short gender;
    unsigned int level;
};

char *format = "%11ld %s %s %d\n";


// 用指向结构体变量的数组做实参
void out_put(struct Student stu[], int num){
    for (int i=0; i<num; i++){
        printf(format, stu[i].ID, stu[i].name, stu[i].gender==0?"female":"male", stu[i].level);
    }
}


// 用指向结构体变量的指针做实参
void out_put2(struct Student *stu, int num){
    struct Student *pt = stu;
    while(pt < stu+num){
        printf(format, pt->ID, pt->name, pt->gender==0?"female":"male", pt->level);
        pt ++;
    }
}


void max_level(struct Student stu[], int num){
    struct Student max_level_stu = stu[0];
    for (int i=0; i<num; i++){
        if (max_level_stu.level < stu[i].level) max_level_stu = stu[i];
    }
    printf(format, max_level_stu.ID, max_level_stu.name, max_level_stu.gender==0?"female":"male", max_level_stu.level);
}


struct Student max_lavel2(struct Student stu[], int num){
    struct Student *pt = stu, max_level_stu = *(stu+0);
    while (pt < stu+num){
        if (max_level_stu.level < pt->level) max_level_stu = *pt;
        pt ++ ;
    }
    return max_level_stu;
}


int main(){
    struct Student stu[len] = {
        {2018060101, "andou", 0, 234},
        {2018060102, "isabella", 0, 94},
        {2018060103, "sirius", 1, 294},
        {2018060104, "nanami", 0, 103},
        {2018060105, "ruki", 0, 256}
    };
    
    //out_put(stu, len);
    out_put2(stu, len);

    printf("\nmax level student:\n");
    // max_level(stu, len);

    struct Student max_level_stu;
    max_level_stu = max_lavel2(stu, len);
    printf(format, max_level_stu.ID, max_level_stu.name, max_level_stu.gender==0?"female":"male", max_level_stu.level);

    return 0;
}