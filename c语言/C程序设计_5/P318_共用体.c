/*
    共用体 : 用同一段内存单元存放不同类型的变量.

    共用体变量所占的内存长度等于最长的成员的长度.

    使用场景
        把一个段整形变量, 一个字符型变量和一个实型变量放在同一个地址开始的内存单元中.
        以上3个变量在内存中占的字节数不同, 但都从同一地址开始存放, 也就是使用覆盖技术, 后一个数据覆盖了前面的数据.
        如97在int成员变现为整形, 字符型成员表现为'a'.

    使用方式
        union 共用体名{
            成员列表;
        } 变量列表;

        不能同时初始化多个共用体变量的成员变量, 只能初始化其中一个, 因为它们都共用一个内存地址.
        多次赋值, 最后一次赋值为最终值.

        union 共用体名 变量名;
*/

# include "stdio.h"
# include "string.h"


// 无名称结构体类型
struct {
    int num;
    char name[32];
    unsigned short gender;
    char job;
    // 如果是学生, 给予class值; 如果是教师, 给予position值
    union {
        int class;
        char position[16];
    } category;
} person[2];


int main(){
    char * format_student = "编号: %d, 名称: %s, 性别: %s, 角色: %c, 班级: %d\n",
         * format_teacher = "编号: %d, 名称: %s, 性别: %s, 角色: %c, 教务: %s\n";
    
    // 学生
    person[0].num = 1;
    strcpy(person[0].name, "Mia");
    person[0].gender = 0;
    person[0].job = 's';
    person[0].category.class = 501;
    // 教师
    person[1].num = 2;
    strcpy(person[1].name, "James");
    person[1].gender = 1;
    person[1].job = 't';
    strcpy(person[1].category.position, "English");

    printf(format_student, person[0].num, person[0].name, person[0].gender==0?"female":"male", 
            person[0].job, person[0].category.class);
    printf(format_teacher, person[1].num, person[1].name, person[1].gender==0?"female":"male", 
            person[1].job, person[1].category.position);

}