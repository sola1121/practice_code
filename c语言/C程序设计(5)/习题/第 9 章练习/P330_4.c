# include "stdio.h"

# define len 2

struct Student {
    unsigned int num;
    char name[32];
    float score[3];
};


void print(struct Student stus[]){
    for (int i=0; i<len; i++){
        printf("%d %s ", stus[i].num, stus[i].name);
        for (int s=0; s<3; s++){
            printf("%.1f ", stus[i].score[s]);
        }
        printf("\n");
    }
}


int main(){
    struct Student stus[len];
    
    for (int i=0; i<len; i++){
        printf("输入第%d个学生数据\n编号: ", i+1);
        scanf("%u", &stus[i].num);
        printf("名称: ");
        scanf("%s", stus[i].name);
        for (int s=0; s<3; s++){
            printf("分数%d: ", s+1);
            scanf("%f", &stus[i].score[s]);
        }
    }

    printf("\n\n输入的内容为:\n");
    print(stus);

    return 0;
}