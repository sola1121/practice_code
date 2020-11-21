/*
    13人围成一圈, 从第1个人开始顺序报号1, 2, 3. 凡报到3者退出. 找出最后留在圈子中的人原来的序号. 
    使用链表实现.
*/

#include <stdio.h>


struct Person{
    int num;
    struct Person *next;
};


int main(){

    struct Person person[13];   //定义结构体变量数组

    // 此循环给13个人标注序号，1对应第一个人，以此类推，同时实现循环链表，当到达链表最后一个时，地址指向开头。
    int i;
    for (i=0; i<13; i++){
        person[i].num = i+1;
        if (i==12) person[i].next = &person[0];
        else person[i].next = &person[i+1];
    }
    
    // 循环报号，当每次报到第2个人时，next指针直接跳过下一个变量，指向下下个变量，当next指针指向自己时结束循环。
    struct Person *p;
    for (p=person, i=0; p->next!=p; p=p->next){
        i++;
        if (i%2==0){
            p->next=p->next->next;
            i=0;
        }
    }
    printf("The number is %d\n", p->num);   // 输出结果

    return 0;
}