# include "stdio.h"
# include "stdlib.h"
# include "time.h"


struct Student {
    int num;
    float score;
    struct Student *next;
};


void output_chain(struct Student * pt){
    printf("输出链表:\n");
    while (pt->next != NULL){
        printf("%d, %.1f\n", pt->num, pt->score);
        pt = pt->next;
    }
}


struct Student * create_chain(){
    struct Student *head, *previous, *current;

    head = previous = current = (struct Student*) malloc(sizeof(struct Student));

    current->num = 1;
    current->score = rand()%100;

    for (int i=2; i<=20; i++){
        previous = current;

        current = (struct Student*) malloc(sizeof(struct Student));
        current->num = i;
        current->score = rand()%100;

        previous->next = current;
    }
    current->next = NULL;

    return head;
}


struct Student * insert_chain(struct Student * head, struct Student * item){
    struct Student * current;

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


struct Student * delete_chain(struct Student * head, struct Student * item){
    struct Student *previous, *current;

    if (head == NULL){
        printf("链表头为空!\n");
        return NULL;
    }

    current = head;
    while (current->next != NULL){
        if (current->num == item->num){
            if (current == head){
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

    struct Student * head;

    head = create_chain();
    output_chain(head);

    struct Student to_insert = {.num=1, .score=13.3}, 
                   to_delete = {.num=1};
    
    printf("\n向链表中插入: %d, %.1f\n", to_insert.num, to_insert.score);
    head = insert_chain(head, &to_insert);
    output_chain(head);

    printf("\n从链表中删除: %d, %.1f\n", to_delete.num, to_delete.score);
    head = delete_chain(head, &to_delete);
    output_chain(head);

    return 0;
}