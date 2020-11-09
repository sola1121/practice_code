# include "stdio.h"
# include "string.h"
# include "time.h"

# define len 10


char * generate_name(){
    int i = 0, length = 0;
    length = rand()%31+1;
    static char name[32];
    while (i<length) {
        name[i] = rand()%26+97;
        i++;
    }
    name[length] = '\0';
    return name;
}


struct Student {
    unsigned int num;
    char name[32];
    float score[3];
};


void out_put(struct Student stus[]){
    float sum = 0;
    for (int i=0; i<len; i++){
        sum = 0;
        printf("%d %s ", stus[i].num, stus[i].name);
        for (int s=0; s<3; s++){
            sum += stus[i].score[s];
            printf("%.1f ", stus[i].score[s]);
        }
        printf("平均分: %.2f\n", sum/3);
    }
}


void max_score(struct Student stus[]){
    int max_i = 0;
    for (int i=0; i<len; i++){
        for (int s=0; s<3; s++){
            if (stus[max_i].score[s] < stus[i].score[s]) max_i = i;
        }
    }
    printf("\n拥有最高分: %d %s %.1f %.1f %.1f 平均: %.2f\n", 
            stus[max_i].num, stus[max_i].name, stus[max_i].score[0], stus[max_i].score[1], stus[max_i].score[2],
            (stus[max_i].score[0]+stus[max_i].score[1]+stus[max_i].score[2])/3);
}


int main(){
    srand((unsigned)time(NULL));
    struct Student stus[len];

    for (int i=0; i<len; i++){
        stus[i].num = i+1;
        strcpy(stus[i].name, generate_name());
        for (int s=0; s<3; s++){
            stus[i].score[s] = rand()%100;
            if (stus[i].score[s]<60) stus[i].score[s] += rand()%40;   // 让及格率高点
        }
    }

    out_put(stus);
    max_score(stus);

    return 0;
}