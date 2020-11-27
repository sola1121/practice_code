# include "stdio.h"
# include "stdlib.h"
# include "time.h"


struct Student {
    int num;
    float score;
    struct Student *next;
};


struct Student * create_chain(){
    struct Student *head, *previous, *current;

    head = previous = current = (struct Student *) malloc(sizeof(struct Student));

    current->num = 1;
    current->score = rand()%100;

    for (int i=1; i<=20; i++){
        previous = current;

        current = (struct Student *)malloc(sizeof(struct Student));
        current->num = i+1;
        current->score = rand()%100;

        previous->next = current;
    }
    current->next = NULL;

    return head;
}


void output_chain(struct Student *pt){
    printf("输出链表:\n");
    while (pt->next != NULL){
        printf("%d, %.1f\n", pt->num, pt->score);
        pt = pt->next;
    }
}


// 按num顺序插入
struct Student * insert_chain_item(struct Student *head, struct Student *item){
    struct Student *current;

    if (head == NULL){
        head = item;
        head->next = NULL;
        return head;
    }

    current = head;
    while (current->next != NULL){
        if (current->num >= item->num){
            item->next = current->next;
            current->next = item;
            break;
        }
        current = current->next;
    }

    if (current->next == NULL){
        current->next = item;
        item->next = NULL;
    }

    return head;
}


// 项链表头插入
struct Student * insert2first_item(struct Student *head, struct Student *item){
    item->next = head;
    return item;
}


// FIXME: 向尾部插入会多一个21, 难道是create时候创建的? 而无法正常 向链表末尾插入
struct Student * insert2end_item(struct Student *head, struct Student *item){
    struct Student *current;

    current = head;
    while(current->next->next != NULL){
        current = current->next;
    }

    current->next = item;
    item->next = NULL;

    return current;
}


int main(){
    srand((unsigned)time(NULL));

    struct Student *head;
    head = create_chain();
    output_chain(head);

    struct Student item1, item2, item3;
    item1.num = 4, item1.score = 11.11;
    item2.num = -100, item2.score = 22.22;
    item3.num = 100, item3.score = 33.33;

    printf("\n按照顺序向链表中插入节点: %d, %.1f\n", item1.num, item1.score);
    head = insert_chain_item(head, &item1);
    output_chain(head);

    printf("\n向链表头插入节点: %d, %.1f\n", item2.num, item2.score);
    head = insert2first_item(head, &item2);
    output_chain(head);
    
    printf("\n向链表尾插入节点: %d, %.1f\n", item3.num, item3.score);
    head = insert2end_item(head, &item3);
    output_chain(head);

    return 0;
}