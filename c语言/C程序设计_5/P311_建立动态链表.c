/*
    建立动态链表是指在程序执行过程中从无到有地建立起一个链表, 
    即一个一个地开辟结点和输入各个结点数据, 并建立起前后相链的关系.
*/

# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "time.h"

# define LEN sizeof(struct Student)

unsigned long count = 0;


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
    int num;
    char name[32];
    struct Student *next;
};

int chain_len;   // 使用全局变量用来记录链表的长度

struct Student * create_stu(){
    struct Student * head;   // 将返回的链头
    head = NULL;

    struct Student *pt1, *pt2;   // pt1总指向最后一个节点, pt2指向pt1前一个节点
    pt1 = pt2 = (struct Student *) malloc(LEN);   // 开辟一个新单元

    // 对pt1中的成员进行随机赋值
    pt1->num = (int) rand()%100;
    strcpy(pt1->name, generate_name());

    chain_len = 0;   // 初始化链表的长度记录变量
    while (pt1->num != 0){   // 当num没有随机到0的时候, 生成一个链表
        chain_len += 1;

        if (chain_len==1) head = pt1;   // 当链表只有一个时, head指向链表头
        else pt2->next = pt1;   // 上一个节点的next指向新的节点

        pt2 = pt1;  // pt2指向pt1, 之后这个pt1将会指向新的内存地址

        // 让pt1指向一个新的单元, 然后为其赋值
        pt1 = (struct Student *)malloc(LEN);
        pt1->num = (int) rand()%100;
        strcpy(pt1->name, generate_name());
    }
    pt2->next = NULL;   // 最后的pt1指向一个未知的
    return head; 
}


// 输出整个链表
void out_put(struct Student * stu){
    int count = 0;
    while(stu->next != NULL){
        printf("%d, %s\n", stu->num, stu->name);
        stu = stu->next;
    }
}


int main(){
    srand((unsigned)time(NULL));

    struct Student *pt;
    pt = create_stu();
    printf("链表长度: %d\n\n", chain_len);
    printf("%d , %s\n", pt->num, pt->name);

    out_put(pt);

    return 0;
}