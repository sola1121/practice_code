# include "stdio.h"
# include "stdlib.h"
# include "time.h"


struct Student{
    int num;
    float score;
    struct Student *next;
};


struct Student * create_chains(){
    struct Student *head, *current, *previous;   // head作为头, current指向当前, previous指向上一个

    head = previous = current = (struct Student *) malloc(sizeof(struct Student));

    current->num = 1;
    current->score = rand()%100;

    for (int i=2; i<=20; i++){
        previous = current;

        current = (struct Student *) malloc(sizeof(struct Student));
        current->num = i;
        current->score = rand()%100;

        previous->next = current;
    }
    current->next = NULL;

    return head;
}


void output_chain(struct Student *pt){
    printf("输出链表:\n");
    while (pt->next != NULL){
        printf("%2d, %.1f\n", pt->num, pt->score);
        pt = pt->next;
    }
}


struct Student * delete_chain_item(struct Student *head, int num){
    struct Student *previous, *current;

    if (head == NULL){
        printf("链表为空!\n");
        return head;
    }

    // 通过循环寻找满足删除条件的节点, 最后current指向需要删除的节点
    current = head;
    while (num != current->num && current->next != NULL){   // 当前指向的节点不为指定删除的并且不是最后一个节点
        previous = current;
        current = current->next;
    }

    // 去除current指向的节点
    if (num == current->num){
        if (current == head) head = current->next;   // 当需要删除的节点是头节点
        else previous->next = current->next;   // 上一个节点的next指向当前节点的next
    } else {
        printf("删除条件 %d, 没有符合的节点.\n", num);
    }
}


int main(){
    srand((unsigned)time(NULL));

    struct Student *head;
    head = create_chains();
    output_chain(head);

    int del_num = 14;
    printf("\n删除%d节点\n", del_num);
    delete_chain_item(head, del_num);
    output_chain(head);

    return 0;
}