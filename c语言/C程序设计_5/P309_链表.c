/*
    链表（Linked list）是一种常见的基础数据结构，是一种线性表，但是并不会按线性的顺序存储数据，而是在每一个节点里存到下一个节点的指针(Pointer)。
    由于不必须按顺序存储，链表在插入的时候可以达到O(1)的复杂度，比另一种线性表顺序表快得多，但是查找一个节点或者访问特定编号的节点则需要O(n)的时间，而顺序表相应的时间复杂度分别是O(logn)和O(1)。

    链表中每一个元素称为"结点", 每个"结点"都应该包括两个部分 1. 用户需要用的实际数据. 2. 下一个结点的地址.
*/

# include "stdio.h"


struct Student {
    unsigned short num;
    char * name;
    struct Student * next;
};


char *format = "%d %s\n";


int main(){
    struct Student chain1, chain2, chain3, * head, *pt;

    chain1.num = 101; chain1.name = "锁链1";
    chain2.num = 102; chain2.name = "锁链2";
    chain3.num = 103; chain3.name = "锁链3";

    head = &chain1;   // 将chain1的起始地址赋给头指针
    chain1.next = &chain2;
    chain2.next = &chain3;
    chain3.next = NULL;

    pt = head;   // pt指向头结点

    while(pt!=NULL){
        printf(format, pt->num, pt->name);
        pt = pt->next;
    }

    return 0;
}