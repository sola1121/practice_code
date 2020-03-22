#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"

#define name_len 6
#define peo_num 10


void print_info(char staffs[peo_num][name_len], unsigned int ids[peo_num]){
    for (size_t i = 0; i < peo_num; i++){
        for (size_t w=0; w<name_len; w++){
            printf("%c", staffs[i][w]);
        }
        printf("  %d\n", ids[i]);
    }
}


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

    // 打印
    print_info(container_staffs, container_ids);
}


// 按工号排序
void sort_employee(char staffs[peo_num][name_len], unsigned int ids[peo_num]){
    char temp_name[name_len] = " ";
    unsigned int temp_num = 0;
    for (int m=0; m<peo_num; m++){
        for (int n=0; n<peo_num-m-1; n++){
            if (ids[n] > ids[n+1]){
                // 将工号进行排序
                temp_num = ids[n];
                ids[n] = ids[n+1];
                ids[n+1] = temp_num;
                // 将对应的人民进行排序
                for (int name=0; name<name_len; name++){
                    temp_name[name] = staffs[n][name];
                    staffs[n][name] = staffs[n+1][name];
                    staffs[n+1][name] = temp_name[name];
                }
            }
        }
    }

    // 打印
    print_info(staffs, ids);
}


// 二分法查找工号
int find_id(unsigned int ids[peo_num], unsigned int serach){
    int low = -1, high = peo_num+1, sub_point = 0,    // 注意这里的low和high的取值, 这是让下标为0和为peo_num的元素也纳入判断
        count = 0, limit = log2((double) peo_num+1);
    sub_point = (low+high)/2;
    while (ids[sub_point]!=serach && count<=limit){
        if (serach < ids[sub_point])
            high = sub_point;
        else if (serach > ids[sub_point])
            low = sub_point;
        count += 1;
        sub_point = (low+high)/2;
    }
    if (count >= limit)   // 判断超过最大次 log2(n+1) 时, 估计就没有要找的了, 这是让下标超过元素
        sub_point = peo_num + 1;
    return sub_point;
}


int main(){
    srand((unsigned) time(NULL));

    char staffs[peo_num][name_len];
    unsigned int ids[peo_num];

    // 生成员工名与对应工号
    printf("生成的人名与对应的工号:\n");
    generate_staff(staffs, ids);

    // 使用冒泡对两个容器变量进行冒泡排序, 名字跟随工号对应排序
    printf("\n进行按工号排序:\n");
    sort_employee(staffs, ids);

    // 对排序好的内容使用二分查找
    unsigned int search = 0, result_sub=0;
    printf("\n查找工号: ");
    scanf("%d", &search);
    result_sub = find_id(ids, search);
    if (result_sub > peo_num){
        printf("没有找到.\n");
    } else {
        printf("\n");
        for (int n=0; n<name_len; n++)
            printf("%c", staffs[result_sub][n]);
        printf(" %d\n", ids[result_sub]);
    }

    return 0;
}