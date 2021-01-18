# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "time.h"

# define LEN 16


char * generate_string(){
    static char result[LEN];
    for (int i=0; i<LEN; i++){
        result[i] = rand()%26 + 97;
    }
    result[LEN] = '\0';
    return result;
}


struct Student {
    int num;
    char name[LEN];
    struct Student * next;
};


void output_chain(struct Student *head){
    struct Student *pt = head;
    printf("输出链表: \n");
    while (pt->next != NULL){
        printf("num: %2d, name: %s\n", pt->num, pt->name);
        pt = pt->next;
    }
}


struct Student * create_chain(int start_num){
    struct Student *head, *previous, *current;

    head = previous = current = (struct Student *) malloc(sizeof(struct Student));
    current->num = start_num;
    strcpy(current->name, generate_string());

    for(int i=start_num; i<start_num+20; i++){
        previous = current;

        current = (struct Student *) malloc(sizeof(struct Student));
        current->num = i+1;
        strcpy(current->name, generate_string());

        previous->next = current;
    }
    current->next = NULL;

    return head;
}


// 将s2中与s1中的相同num的节点移除
struct Student * remove_same_item(struct Student *head_s1, struct Student *head_s2){
    struct Student *pt = head_s1, *current, *previous;

    while(pt->next != NULL){
        current = head_s2;
        while(current->next != NULL){
            previous = current;
            if (current->num == pt->num){
                if (current == head_s2){
                    head_s2 = head_s2->next;
                    current = head_s2;
                } else {
                    previous->next = current->next;
                }
            }
            current = current->next;
        }
        pt = pt->next;
    }

    return head_s2;
}


int main(){
    srand((unsigned) time(NULL));

    struct Student * head_s1, * head_s2;

    head_s1 = create_chain(1);
    output_chain(head_s1);
    head_s2 = create_chain(16);
    output_chain(head_s2);

    printf("进行s2的去重 \n");
    head_s2 = remove_same_item(head_s1, head_s2);
    output_chain(head_s2);

    return 0;
}


