# include "stdio.h"
# include "string.h"
# include "stdlib.h"
# include "time.h"

/*
    5个学生, 每个学生有3门成绩, 包含学号, 姓名, 3科成绩, 计算出平均成绩, 将原有数据和计算出的平均分数存放在磁盘中.

    int sprintf(char * s, const char *format, ...)
    将格式化内容赋值给s
*/

# define NUM 5

char * filepath_studs = "./do_not_push_studs.txt";

struct Student{
    int id;
    char name[16];
    float score[3];
};


char * generate_string(){
    int i = 0, length = 0;
    length = rand()%15+1;
    static char string[16];   // 字符串
    while (i<length) {
        string[i] = rand()%26+97;
        i++;
    }
    string[length] = '\0';
    return string;
}


void output_studs(struct Student studs[], int len){
    for (int i=0; i<len; i++){
        printf("学号: %d, 姓名: %s, ", studs[i].id, studs[i].name);
        for (int s=0; s<3; s++){
            if (s==0)
                printf("分数: %.1f", studs[i].score[s]);
            else
                printf(", %.1f", studs[i].score[s]);
        }
        putchar('\n');
    }
}


int main(int args, char *argv[]){
    srand((unsigned) time(NULL));
    
    struct Student studs[NUM] = {};

    for (int i=0; i<NUM; i++){
        (studs+i)->id = i+1;
        strcpy((studs+i)->name, generate_string());
        for (int s=0; s<3; s++){
            *((studs+i)->score+s) = random() % 99 + 1;
        }
    }
    output_studs(studs, NUM);

    // 开始求出平均值, 并返到文件中
    float sum = 0;
    FILE * fp = NULL;
    char info[128] = {}, num_str[16];
    if ((fp=fopen(filepath_studs, "w"))==NULL){
        puts("文件打开失败.\n");
        exit(0);
    }
    for (int i=0; i<NUM; i++){
        sum = 0;
        sprintf(info, "%d,%s", (studs+i)->id, (studs+i)->name);
        fputs(info, fp);
        for (int s=0; s<3; s++){
            sprintf(num_str, ",%.1f", *((studs+i)->score+s));
            fputs(num_str, fp);
            sum += *((studs+i)->score+s);
        }
        sprintf(num_str, ",%.1f", sum/3);
        fputs(num_str, fp);
        fputc('\n', fp);
    }
    return 0;
}