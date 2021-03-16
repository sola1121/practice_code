# include "stdio.h"
# include "stdlib.h"

/*
    从9中的数据文件中删除一个
*/

# define NUM 16

// 打工人
struct Employee{
    unsigned int id;
    char name[16], address[64], health_status[32], education[32];
    unsigned short gender, age;
    float salary;
};


int main(int args, char * argv[]){

    char * employee_file = "./do_not_push_employee.dat";
    char * new_employee_file = "./do_not_push_employee(2).dat";

    FILE * fp = NULL;
    if((fp=fopen(employee_file, "rb"))==NULL){
        puts("文件打开失败.");
        exit(0);
    }
    if (fgetc(fp) == EOF){
        puts("文件内容为空.");
        exit(0);
    }
    rewind(fp);

    // 开始对文件进行读取, 对满足工号的进行跳过, 不存入新生的数组中, 达到删除的效果
    int count = 0, 
        to_delete=10;   // 用来删除的人的工号
    struct Employee temp,  
                    * empls = malloc(sizeof(struct Employee)*NUM-1);   // 新生成的打工表, 这里用empls[NUM-1]会出问题, 栈溢出??
    while (!feof(fp)){
        fread(&temp, sizeof(struct Employee), 1, fp);
        if (temp.id == to_delete) 
            continue;
        else {
            *(empls+count) = temp;
            ++ count;
        }
    }

    // 处理后的新数组
    puts("工号, 姓名, 性别, 年龄, 工资, 受教育, 健康状况, 住址");
    char * format_output = "%d,%s,%c,%d,%.2f,%s,%s,%s\n";
    for (int i=0; i<NUM-1; i++){
        printf(format_output, (empls+i)->id, (empls+i)->name, (empls+i)->gender > 0?'M':'F', (empls+i)->age, \
                              (empls+i)->salary, (empls+i)->education, (empls+i)->health_status, (empls+i)->address);
    }

    // 开始写入新的文件
    if ((fp=freopen(new_employee_file, "wb", fp))==NULL){
        puts("重新代开文件失败.");
        exit(0);
    }
    for (int i=0; i<NUM-1; i++){
        fwrite(empls+i, sizeof(struct Employee), 1, fp);
    }

    fclose(fp);
    return 0;
}