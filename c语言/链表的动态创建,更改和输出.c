# include "stdio.h"
# include "stdlib.h"
# include "time.h"
# include "string.h"

// REVIEW: https://www.jianshu.com/p/64f1abf87901


char * generate_string(){
    static char result[16];
    int i=0;
    while (i<rand()%15+1){
        result[i] = rand()%26+97;
        i++;
    }
    result[i] = '\0';
    return result;
}


struct SelfType{
    int num;
    char str[32];
    struct SelfType *next;
};


void output_chain(struct SelfType * pt){
    int count = 0;
    while(pt->next != NULL){
        printf("%d, %s\n", pt->num, pt->str);
        pt = pt->next;
        count += 1;
    }
    printf("\n链表长度: %d\n", count);
}


// P311 使用的方式
struct SelfType * create_chains(){
    typedef struct SelfType Sepe;
    Sepe *head, *pt1, *pt2;   // head作为头指针, pt1总指向最后一个节点, pt2指向pt1前一个节点

    head = pt1 = pt2 = (Sepe *) malloc(sizeof(Sepe));

    // 生成第一个节点内容
    strcpy(pt1->str, generate_string());
    pt1->num = rand()%20;

    while (pt1->num != 0){
        pt2 = pt1;   // pt1要去指向新节点, pt2指向pt1原来指向的节点

        pt1 = (Sepe *) malloc(sizeof(Sepe));
        pt2->next = pt1;   // 上一个节点的next指向新的节点

        // 对当前pt1赋予内容
        strcpy(pt1->str, generate_string());
        pt1->num = rand()%20;
    }
    pt1->next = NULL;   // 将最后一个节点的next置为空

    return head;   // 返回头指针
}


// 头插法
struct SelfType * create_chains_first(){
    typedef struct SelfType Sepe;
    Sepe *head = (Sepe *) malloc(sizeof(Sepe));
    head->next = NULL;
    Sepe * current = NULL;

    for (int i=0; i<10; i++){
        current = (Sepe *) malloc(sizeof(Sepe));

        // 向当前链表中添加值
        strcpy(current->str, generate_string());
        current->num = rand()%20;

        // 开始向后面进行依序向后移动
        current->next = head->next;
        head->next = current;
    }
    return head;
}


// 尾插法
struct SelfType * create_chains_end(){
    typedef struct SelfType Sepe;
    Sepe * head = (Sepe *) malloc(sizeof(Sepe));
    head->next = NULL;
    Sepe * previous = head;
    for (int i=0; i<10; i++){
        Sepe * current = (Sepe *) malloc(sizeof(Sepe));

        // 向当前链表中添加数据
        strcpy(current->str, generate_string());
        current->num = rand()%20;

        current->next = previous->next;   // 连接到链表尾部
        previous->next = current;

        previous=current;   // 更新到前面节点
    }

    return head;
}


// 向链表中插入, 使用头插入的方式
void insert_chains(struct SelfType *head, int value_i, char value_c[32]){
    typedef struct SelfType Sepe;
    Sepe * current = (Sepe *) malloc(sizeof(Sepe));

    strcpy(current->str, value_c);
    current->num = value_i;

    /* 先保证新节点指向父节点的下一个节点
       然父节点指向新节点
       这样做的目的可以保证链表不被破坏
     */
    current->next = head->next;
    head->next = current;
}


struct SelfType * delete_chain(struct SelfType * head, struct SelfType * item){
    typedef struct SelfType Sepe;
    Sepe *previous, *current;

    current = head;
    while (current->next != NULL){
        if (current->num == item->num){
            if (current == head) {
                head = head->next;
            } else {
                previous->next = current->next;
            }
            break;
        }
        previous = current;
        current = current->next;
    }

    return head;
}


int main(){
    srand((unsigned)time(NULL));

    struct SelfType *obj1, *obj2, *obj3;
    obj1 = create_chains();

    output_chain(obj1);
    printf("\n\n");


    obj2 = create_chains_first();
    
    output_chain(obj2);
    printf("\n\n");

    obj3 = create_chains_end();
    output_chain(obj3);

    return 0;
}
