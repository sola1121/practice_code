#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"

#define name_len 6
#define peo_num 10


// 随机生成人名和职工号
void generate_staff(char container_staffs[peo_num][name_len], unsigned int container_ids[peo_num]){
    // 生成人名和工号
    char words_dict[26] = "abcdefghijklmnopqrstuvwxyz";
    for (int peo=0; peo<peo_num; peo++){
        for (int w=0; w<name_len; w++){
            int temp = rand() % 26;
            container_staffs[peo][w] = words_dict[temp];
        }
    }

    for (int peo=0; peo<peo_num; peo++){
        container_ids[peo] = (unsigned int)(rand());
    }

    // 输出生成结果
    for (size_t i = 0; i < peo_num; i++){
        for (size_t w=0; w<name_len; w++){
            printf("%c", container_staffs[i][w]);
        }
        printf("  %d\n", container_ids[i]);
    }
}


// 按工号排序
void sort_employee(char staffs[peo_num][name_len], unsigned int ids[peo_num]){
    char temp_name[name_len] = ' ';
    unsigned int temp_num = 0;
    for (int m=0; m<peo_num; m++){
        for (int n=0; n<peo_num-m-1; n++){
            if (ids[n] > ids[n+1]){
                temp_num = ids[n];
                ids[n] = ids[n+1];
                ids[n+1] = temp_num;
                // TODO: 还需要将对应的人民进行排序
            }
        }
    }
}


// 二分法查找工号
void find_id(){

}


int main(){
    srand((unsigned) time(NULL));

    char staffs[peo_num][name_len];
    unsigned int ids[peo_num];

    generate_staff(staffs, ids);

    return 0;
}