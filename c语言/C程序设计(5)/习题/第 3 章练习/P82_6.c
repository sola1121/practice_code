#include "stdio.h"

/* 输入 China 输出 Glmre */

int main(){
    char c1, c2, c3, c4, c5;
    int new_c1, new_c2, new_c3, new_c4, new_c5;

    scanf("%c%c%c%c%c", &c1, &c2, &c3, &c4, &c5);

    new_c1 = (int)c1 + 4;
    new_c2 = (int)c2 + 4;
    new_c3 = (int)c3 + 4;
    new_c4 = (int)c4 + 4;
    new_c5 = (int)c5 + 4;

    printf("printf: %c%c%c%c%c\n", new_c1, new_c2, new_c3, new_c4, new_c5);

    putchar(new_c1);
    putchar(new_c2);
    putchar(new_c3);
    putchar(new_c4);
    putchar(new_c5);
    putchar('\n');

    getchar();
    return 0;
}
