# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "time.h"

/*
    将6中已排序学生成绩文件插入一个新人, 同样包含学号, 姓名, 三门课成绩, 按成绩高低排列, 并输出到新文件
*/

# define NUM 5

char * filepath_studs = "./do_not_push_studs(2).txt";
char * new_filepath_studs = "./do_not_push_studs(3).txt";

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


float average_score(struct Student studs, int len){
    float sum = 0;
    for (int i=0; i<len; i++)
        for (int s=0; s<len ; s++)
            sum += studs.score[s];
    return sum/len;
};


int main(){
    srand((unsigned) time(NULL));

    FILE *fp = NULL;
    if ((fp=fopen(filepath_studs, "r"))==NULL){
        puts("打开文件失败.");
        exit(0);
    }

    if (fgetc(fp)==EOF){
        puts("文件内容为空.");
        exit(0);
    }

    // 读取原有的学生
    int i=0;
    char ch = '\0';
    struct Student studs[NUM] = {};
    while(i<NUM && !feof(fp)){
        fscanf(fp, "%d,", &(studs[i].id));
        while (ch=fgetc(fp)){   // 因为fscanf()在读入%s的时候会将字符串后面所有的都作为%s, 这里就这样分开来读
            if (ch!=',') sprintf(studs[i].name, "%s%c", studs[i].name, ch);
            else break;
        }
        fscanf(fp, "%f,%f,%f\n",  &(studs[i].score[0]), &(studs[i].score[1]), &(studs[i].score[2]));
        i+=1;
    }
    
    // 创建新人, 并将新人加入学生数组
    struct Student new_studs[NUM+1] = {},
           new_one = {.id=6};
    strcpy(new_one.name, generate_string());
    new_one.score[0] = random()%99+1;
    new_one.score[1] = random()%99+1;
    new_one.score[2] = random()%99+1;

    puts("将插入:");
    printf("%d,%s,%.1f,%.1f,%.1f\n", new_one.id, new_one.name, new_one.score[0], new_one.score[1], new_one.score[2]);

    for (int i=0; i<NUM+1; i++){
        if (i==5)
            new_studs[i] = new_one;
        else
            new_studs[i] = studs[i];
    }

    puts("进行排序.");
    struct Student temp;
    for (int m=0; m<NUM+1; m++){
        for (int n=m+1; n<NUM+1; n++){
            if (average_score(new_studs[m], 3) < average_score(new_studs[n], 3)){
                temp = new_studs[m];
                new_studs[m] = new_studs[n];
                new_studs[n] = temp;
            }
        }
    }

    // 写入新文件
    if ((fp=fopen(new_filepath_studs, "w"))==NULL){
        puts("文件打开失败");
        exit(0);
    }

    char * string = (char*) malloc(sizeof(struct Student));
    for (int i=0; i<NUM+1; i++){
        sprintf(string, "%d,%s,%.1f,%.1f,%.1f\n", \
                new_studs[i].id, new_studs[i].name, new_studs[i].score[0], new_studs[i].score[1], new_studs[i].score[2]);
        fputs(string, fp);
        printf("%d,%s,%.1f,%.1f,%.1f\n", \
                new_studs[i].id, new_studs[i].name, new_studs[i].score[0], new_studs[i].score[1], new_studs[i].score[2]);
    }

    return 0;
}