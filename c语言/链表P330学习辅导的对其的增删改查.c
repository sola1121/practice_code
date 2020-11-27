# include "stdio.h"
# include "malloc.h"


# define LEN sizeof(struct Student)


struct Student{
    long num;
    float score;
    struct Student *next;
};


int n;


int main(){
    struct Student * create();
    struct Student * delete(struct Student *, long);
    struct Student * insert(struct Student *, struct Student *);
    void print(struct Student *);

    struct Student *head, stu;
    long del_num;
    printf("输入记录: \n");
    head = create();
    print(head);

    printf("输入需要删除的记录num: \n");
    scanf("%ld", &del_num);
    head = delete(head, del_num);
    print(head);

    printf("输入要插入的记录: \n");
    scanf("%ld, %f", &stu.num, &stu.score);
    head = insert(head, &stu);
    print(head);

    return 0;
}


// 创建链表的函数
struct Student * create(){
    struct Student *head, *p1, *p2;   // head: 链表头; p1: 代表当前节点; p2: 代表上一个节点
    n = 0;
    p1 = p2 = (struct Student *) malloc(LEN);
    scanf("%ld, %f", &p1->num, &p1->score);
    head = NULL;
    while (p1->num != 0){
        n = n+1;
        if (n == 1) head = p1;
        else p2->next = p1;
        p2 = p1;
        p1 = (struct Student *) malloc(LEN);
        scanf("%ld, %f", &p1->num, &p1->score);
    }
    p2 -> next = NULL;

    return head;
}


// 删除节点的函数
struct Student * delete(struct Student * head, long num){
    struct Student *p1, *p2;   // p1: 代表当前节点; p2: 代表上一个节点
    if (head == NULL){
        printf("链表为空!\n");
        return head;
    }

    p1 = head;
    while (num!=p1->num && p1->next!=NULL){
        p2 = p1;
        p1 = p1->next;
    }

    if (num == p1->num){
        if (p1 == head) head = p1->next;
        else p2->next = p1->next;
        printf("删除: %ld\n", num);
        n = n-1;
    } else {
        printf("%ld 编号没有被找到.\n", num);
    }

    return head;
}


// 向链表插入节点的函数
struct Student * insert(struct Student * head, struct Student * stud){
    struct Student *p0, *p1, *p2;

    p1 = head;
    p0 = stud;
    if (head == NULL){
        head = p0;
        p0->next = NULL;
    } else {
        while ((p0->num > p1->num) && (p1->next != NULL)){
            p2 = p1;
            p1 = p1->next;
        }
        if (p0->num <= p1->num){
            if (head == p1) head = p0;
            else p2->next = p0;
            p0->next = p1;
        } else {
            p1->next = p0;
            p0->next = NULL;
        }
    }

    n = n+1;

    return head;
}


// 输出链表
void print(struct Student * head){
    struct Student *p;
    printf("输出链表: \n");
    p = head;
    if (head != NULL)
    do{
        printf("%ld, %5.1lf\n", p->num, p->score);
        p = p->next;
    } while (p != NULL);
}
