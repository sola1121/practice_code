#include "stdio.h"

/*
    有塔 A, B, C. 开始时A上有64个盘子, 盘子大小不等, 大的在下, 小的在上.
    把这64个盘子从A移到C, 但每次只能移动一个盘, 且移动过程中在三个座上都始终保证大盘在下, 小盘在上.
    移动过程中可以使用B.

    思考, 通常的话要把64个盘子从A移到C需要2**64 - 1次移动.
    大体思路:
        1. 将63个盘子从A移到B
        2. 将A剩的一个盘子(这里应该是A,B上最大的)移动到C
        3. 在将B上的移动回A, 将62个盘子移动到B
        4. 以此套娃
    如何将63个盘子从A移到B:
        1. 将62个盘子从A移动到B
        2. 将一个盘子从A移到B
        3. 将62个盘子从C移到B
    在进行以此递归. 如此层层下放, 直到第63次, 将2个盘子从一个移动到另一个.
    1. 将A上n-1个盘借助C先移到B上.
    2. 把A上剩下的一个盘移到C上.
    3. 将n-1个盘从B借助A移到C上.
*/

void hanoi(int, char, char, char);
void move(char, char);

int main(){
    int m = 4;

    printf("%d个盘子移动方式如下:\n", m);
    hanoi(m, 'A', 'B', 'C');

    printf("\n");
    return 0;
}


void hanoi(int n, char one, char two, char three){
    // 将n个盘从one座借助two座, 移到three
    if (n==1)
        move(one, three);   // 最后剩下的一个进行移动, A->C
    else {
        hanoi(n-1, one, three, two);   // 将A上n-1个盘借助C先移到B上
        move(one, three);   // 把A上剩下的一个盘移到C上
        hanoi(n-1, two, one, three);   // 将n-1个盘从B借助A移到C上
    }
}

void move(char x, char y){
    printf("%c -> %c\n", x, y);
}