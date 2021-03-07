# include "stdio.h"
# include "time.h"
# include "stdlib.h"
# include "string.h"


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


struct Student{
    unsigned int num;
    char name[16];
    float score[3];
};


void print(struct Student stus[]){
    for (int i=0; i<5; i++){
        printf("%d %s ", stus[i].num, stus[i].name);
        for (int s=0; s<3; s++){
            printf("%.1f ", stus[i].score[s]);
        }
        printf("\n");
    }
}


int main(){
    srand((unsigned)time(NULL));

    struct Student stus[5];

    for (int i=0; i<5; i++){
        stus[i].num = rand()%64;
        strcpy(stus[i].name, generate_name());
        for (int s=0; s<3; s++){
            stus[i].score[s] = rand()%100;
        }
    }

    print(stus);

    return 0;
}