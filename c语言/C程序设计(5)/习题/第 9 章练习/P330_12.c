# include "stdio.h"
# include "string.h"
# include "stdlib.h"
# include "time.h"

# define LEN 8

// 输入年龄, 将链表中对应年龄的节点删除

char * generate_string(){
    static char result[LEN];
    for (int i=0; i<LEN; i++){
        result[i] = rand()%26 + 97;
    }
    result[LEN-1] = '\0';
    return result;
}


struct Student {
    int num;
    char name[LEN];
    unsigned short gender;
    unsigned int age;
    struct Student *next;
};


void output_chain(struct Student * pt){
    printf("输出链表: \n");
    while(pt->next != NULL){
        printf("%2d, %s, %s, %d\n", pt->num, pt->name, pt->gender==0?"女":"男", pt->age);
        pt = pt->next;
    }
}


struct Student * create_chain(){
     struct Student *head, *previous, *current;

    head = previous = current = (struct Student *) malloc(sizeof(struct Student));

    current->num = 1;
    strcpy(current->name, generate_string());
    current->gender = (short) rand()%2;
    current->age = (unsigned int) rand()%100+1;

    for (int i=1; i<=20; i++){
        previous = current;

        current = (struct Student *) malloc(sizeof(struct Student));
        current->num = i+1;
        strcpy(current->name, generate_string());
        current->gender = (short) rand()%2;
        current->age = (unsigned int) rand()%100+1;

        previous->next = current;
    }
    current->next = NULL;

    return head;
}


// 将满足条件的全部去掉
struct Student * delete_chain(struct Student * head, unsigned int de_age){
    struct Student *previous, *current;
    current = head;
    
    while (current->next != NULL){
        if (de_age-.0001<=current->age && current->age<=de_age+.0001){
            if (current == head){
                head = head->next;
                current = head;
            } else {
                previous->next = current->next;
            }
        }
        previous = current;
        current = current->next;
    }

    return head;
}


int main(){
    srand((unsigned)time(NULL));

    unsigned int de_age;
    struct Student *head;
    head = create_chain();
    output_chain(head);

    while (1){
        printf("输入需要删除的对应节点的年龄(输入1000以上退出): ");
        scanf("%u", &de_age);
        if (1000<=de_age) break;

        head = delete_chain(head, de_age);
        output_chain(head);
    }

    return 0;
}