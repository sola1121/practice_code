# include "stdio.h"
# include "stdlib.h"
# include "time.h"

# define CHAIN_LEN 19


struct Student {
    int num;
    float score;
    struct Student * next;
};


// 动态创建链表, 可以指定开始的学号
struct Student * create_chain(int start_num){
    int count = 0;
    struct Student *head, *previous, *current;
    head = previous = current = (struct Student *) malloc(sizeof(struct Student));

    current->num = start_num;
    current->score = rand()%100;

    while (count < CHAIN_LEN){
        count += 1;
        previous = current;

        current = (struct Student *) malloc(sizeof(struct Student));
        current->num = start_num + count;
        current->score = rand()%100;

        previous->next = current;
    }
    current->next = NULL;

    return head;
}


struct Student * sort_chain(struct Student *array[], struct Student *head1, struct Student *head2){
    int i = 0;
    struct Student *pt1 = head1, *pt2 = head2, *temp;

    while (pt1->next != NULL){
        array[i] = pt1;
        pt1 = pt1->next;
        i += 1;
    }

    while (pt2->next != NULL){
        array[i] = pt2;
        pt2 = pt2->next;
        i += 1;
    }
    
    for (int m=0; m<CHAIN_LEN*2; m++){
        for (int n=m+1; n<CHAIN_LEN*2-1; n++){
            if (array[m]->num < array[n]->num){
                temp = array[m];
                array[m] = array[n];
                array[n] = temp;
            }
        }
    }

    return array;
}


void output_chain(struct Student *pt){
    printf("\n输出链表: \n");
    while (pt!=NULL){
        printf("%d, %.1f\n", pt->num, pt->score);
        pt = pt->next;
    }
}


void output_array(struct Student *array[], int len){
    printf("\n输出数组: \n");
    for (int i=0; i<len; i++){
        printf("%d, %.1f\n", array[i]->num, array[i]->score);
    }
}


int main(){
    srand((unsigned)time(NULL));

    struct Student *head1, *head2, array[CHAIN_LEN*2];
    head1 = create_chain(1), head2 = create_chain(CHAIN_LEN+2);

    output_chain(head1);
    output_chain(head2);

    sort_chain(array, head1, head2);
    output_array(array, CHAIN_LEN*2);

    return 0;
}