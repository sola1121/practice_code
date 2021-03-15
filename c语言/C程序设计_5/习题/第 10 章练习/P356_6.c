# include "stdio.h"
# include "stdlib.h"
# include "string.h"

/*
    5中生成的数据按已生成的平均数进行排列, 并存入新文件中
*/

# define NUM 5


char * filepath_studs = "./do_not_push_studs.txt";
char * new_filepath_studs = "./do_not_push_studs(2).txt";


struct Student{
    int id;
    char name[16];
    float score[3];
};


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


float average_score(struct Student studs, int len){
    float sum = 0;
    for (int i=0; i<len; i++)
        for (int s=0; s<len ; s++)
            sum += studs.score[s];
    return sum/len;
}


int main(){
    // 从文件中将数据读出来, 放到struct Student studs中
    FILE *fp = NULL;
    if ((fp=fopen(filepath_studs, "r"))==NULL){
        puts("文件打开失败.");
        exit(0);
    }

    if (fgetc(fp)==EOF){
        puts("文件内容为空.");
        exit(0);
    }
    rewind(fp);

    char ch;
    int i = 0;
    float avg = .0;   // 用来接收多的那一位平均数
    struct Student studs[NUM] = {}, temp;
    while(i<NUM && !feof(fp)){
        fscanf(fp, "%d,", &(studs[i].id));
        while (ch=fgetc(fp)){
            if (ch!=',') sprintf(studs[i].name, "%s%c", studs[i].name, ch);
            else break;
        }
        fscanf(fp, "%f,%f,%f,%f\n",  &(studs[i].score[0]), &(studs[i].score[1]), &(studs[i].score[2]), &avg);
        i+=1;
    }

    // 进行排序
    for (int m=0; m<NUM; m++){
        for (int n=m+1; n<NUM; n++){
            if (average_score(studs[m], 3) < average_score(studs[n], 3)){
                temp = studs[m];
                studs[m] = studs[n];
                studs[n] = temp; 
            }
        }
    }

    // 重新输出到新文件
    puts("输出排序好的, 并存入新文件");
    if ((fp=fopen(new_filepath_studs, "w"))==NULL){
        puts("文件打开失败.");
        exit(0);
    }

    char * cat_string = (char *) malloc(sizeof(struct Student));
    for (int i=0; i<NUM; i++){
        printf("%d,%s,%.1f,%.1f,%.1f\n", studs[i].id, studs[i].name, \
                studs[i].score[0], studs[i].score[1], studs[i].score[2]);
        sprintf(cat_string, "%d,%s,%.1f,%.1f,%.1f\n", studs[i].id, studs[i].name, \
                studs[i].score[0], studs[i].score[1], studs[i].score[2]);
        fputs(cat_string, fp);
    }

    fclose(fp);
    return 0;
}