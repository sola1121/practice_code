# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "time.h"


/*
    有一个employee 文件, 包含每个职工姓名, 工号, 性别, 年龄, 住址, 工资, 健康状况, 文化程度.

    并单独从其中抽取出工号, 姓名, 工资另建一个简明职工工资文件.
*/


# define NUM 16


// 打工人
struct Employee{
    unsigned int id;
    char name[16], address[64], health_status[32], education[32];
    unsigned short gender, age;
    float salary;
};

struct EmplyeeBrief{
    unsigned int id;
    char name[16];
    float salary;
};


// 用于生成随机长度字符串, 使用strcpy(目标, generate_string())
char * generate_string(){
    int i = 0, length = 0;
    length = rand()%7 + 1;   // 随机长度
    static char result[8];   // 字符串
    while (i<length) {
        result[i] = rand()%26 + 97;
        i++;
    }
    result[length] = '\0';
    return result;
}


// 用于生成指定长度的随机字符串, 使用strcpy(目标, generate_string(8))
char * generate_string2(int len){
    char * result = (char *) malloc(sizeof(char)*256);   // 字符串
    char ch = '\0';
    for (int i=0; i<len; i++){
        ch = rand()%26 + 97;
        sprintf(result, "%s%c", result, ch);   // strcat(result, &ch);
    }
    result[len] = '\0';

    return result;
}


int main(int args, char * argv[]){
    srand((unsigned) time(NULL));
    srandom((unsigned) time(NULL));

    char * employee_file = "./do_not_push_employee.dat";
    char * brief_employee_file = "do_not_push_employee_brief.dat";

    // 先创建employee.dat文件
    puts("工号, 姓名, 性别, 年龄, 工资, 受教育, 健康状况, 住址");
    char * format_output = "%d,%s,%c,%d,%.2f,%s,%s,%s\n";
    struct Employee empls[NUM] = {};   // 用来装生成的职工信息的容器, 这里也可以不用数组, 因为之后也用不上了
    FILE * fp = NULL;
    if ((fp=fopen(employee_file, "wb"))==NULL){
        puts("文件打开失败.");
        exit(0);
    }
    for (int i=0; i<NUM; i++){
        (empls+i)->id = i+1;
        (empls+i)->age = rand()%65 + 18;
        (empls+i)->gender = rand()%2;
        (empls+i)->salary = random()%9000 + 3000;
        strcpy((empls+i)->name, generate_string());
        strcpy((empls+i)->address, generate_string());
        strcpy((empls+i)->education, generate_string2(8));
        strcpy((empls+i)->health_status, generate_string2(8));
        printf(format_output, (empls+i)->id, (empls+i)->name, (empls+i)->gender > 0?'M':'F', (empls+i)->age, \
                              (empls+i)->salary, (empls+i)->education, (empls+i)->health_status, (empls+i)->address);
        fwrite((empls+i), sizeof(struct Employee), 1, fp);
    }

    // 从创建的emplyee.dat中读取数据, 要单独生成一个简要的
    int count = 0;
    struct Employee empl;   // 用来读取职工信息的
    struct EmplyeeBrief empl_briefs[NUM] = {};   // 用来简要描述的容器
    if ((fp=freopen(employee_file, "rb", fp))==NULL){
        puts("文件重打开失败.");
        exit(0);
    }
    puts("\n重新读取employee.dat");
    puts("工号, 姓名, 性别, 年龄, 工资, 受教育, 健康状况, 住址");
    while (!feof(fp) && count<NUM){
        fread(&empl, sizeof(struct Employee), 1, fp);
        printf(format_output, empl.id, empl.name, empl.gender > 0?'M':'F', empl.age, \
                              empl.salary, empl.education, empl.health_status, empl.address);
        // 向简要描述的容器中写入信息
        (empl_briefs+count)->id = empl.id;
        strcpy((empl_briefs+count)->name, empl.name);
        (empl_briefs+count)->salary = empl.salary;
        count ++;
    }

    // 将单独生成的简要的写入文件
    char * format_output_brief = "%d,%s,%.2f\n";
    if ((fp=freopen(brief_employee_file, "wb", fp))==NULL){
        puts("打开文件失败.");
        exit(0);
    }
    puts("\n向employee_brief.dat中写入内容");
    puts("工号, 姓名, 工资");
    for (int i=0; i<NUM; i++){
        printf(format_output_brief, (empl_briefs+i)->id, (empl_briefs+i)->name, (empl_briefs+i)->salary);
        fwrite((empl_briefs+i), sizeof(struct EmplyeeBrief), 1, fp);
    }

    // 读取简要文件, 看是否写入成功
    puts("\n查看保存的简要文件.");
    puts("工号, 姓名, 工资");
    if ((fp=freopen(brief_employee_file, "rb", fp))==NULL){
        puts("重新代开文件失败.");
        exit(0);
    }
    if (fgetc(fp) == EOF){
        puts("文件内容为空.");
        exit(0);
    }
    rewind(fp);
    
    count =0;
    struct EmplyeeBrief empl_brief;
    while (!feof(fp) && count < NUM){
        fread(&empl_brief, sizeof(struct EmplyeeBrief), 1, fp);
        printf(format_output_brief, empl_brief.id, empl_brief.name, empl_brief.salary);
        count ++;
    }

    return 0;
}