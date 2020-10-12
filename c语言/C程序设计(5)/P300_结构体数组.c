# include "stdio.h"
# include "stdlib.h"
# include "time.h"
# include "string.h"

# define TIMES 16


struct Person{
    char name[20];
    int count;
};

struct Person leader[3] = {"P1", 0, "P2", 0, "P3", 0};


int main(){
    int temp;
    srand((unsigned)time(NULL));
    for (int i=0; i<TIMES; i++){
        temp = rand()%3;
        switch (temp){
        case 0:
            printf("P1 获得加分\n");
            leader[temp].count += 1;
            break;
        case 1:
            printf("P2 获得加分\n");
            leader[temp].count += 1;
            break;
        case 2:
            printf("P3 获得加分\n");
            leader[temp].count += 1;
            break;
        default:
            printf("Error, 判断数: %d\n", temp);
            break;
        }
    }

    printf("\n最后得分: \n");
    for (int i=0; i<3; i++){
        printf("%s : %d\n", leader[i].name, leader[i].count);
    }

    // 按得分进行排序
    // 对Person类型的变量中的各个成员值进行交换赋值
    // char *temp_name;
    // int temp_count = 0;

    // for (int m=0; m<3; m++){
    //     for (int n=m+1; n<3; n++){
    //         if (leader[m].count < leader[n].count){
    //             temp_name = strdup(leader[n].name);
    //             temp_count = leader[n].count;
    //             strcpy(leader[n].name, leader[m].name);
    //             leader[n].count = leader[m].count;
    //             strcpy(leader[m].name, temp_name);
    //             leader[m].count = temp_count;
    //         } 
    //     }
    // }

    // 直接对Person类型变量进行交换
    struct Person temp_person;

    for (int m=0; m<3; m++){
        for (int n=m; n<3; n++){
            if (leader[m].count < leader[n].count){
                temp_person = leader[n];
                leader[n] = leader[m];
                leader[m] = temp_person; 
            }
        }
    }


    printf("\n排序后: \n");
    for (int i=0; i<3; i++){
        printf("%s : %d\n", leader[i].name, leader[i].count);
    }

    return 0;
}