# include "stdio.h"


int main(){
    struct Stu {
        char name[32];
        short age;
        int gender;
    } student1 = {"Tom", 24, 1};   // 定义结构体的时候, 同时声明其结构体类型的变量

    struct Stu student2 = {"Jerry", 23, 1};   // 使用已有的结构体类型, 声明一个结构体变量

    struct Stu student3 = {.age=16};   // C99标准允许在声明一个结构体变量的时候, 为其某一成员初始化
    
    printf("name: %s age: %hd gender: %s\n", student1.name, student1.age, student1.gender==1?"male":"female");
    printf("name: %s age: %hd gender: %s\n", student2.name, student2.age, student2.gender==1?"male":"female");
    printf("age: %hd\n", student3.age);   // 没有被赋值的成员, 数值型给予0, 字符型给予'\0', 指针型给予NULL

    printf("单独为student3的name和gengder赋值成员赋值: ");
    scanf("%s%d", student3.name, &student3.gender);   // student3.name本来就是一个数组名, 不用在前面加一个&
    printf("现在的student3, name: %s, gender: %s\n", student3.name, student3.gender==1?"male":"female");

    return 0;
}