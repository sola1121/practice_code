#include "stdio.h"

void main(){
    int x, y;
    printf("enter x: ");
    scanf("%d", &x);
    y = -1;

    // 书写方式1
    if (x!=0)
        if (x>0)
            y = 1;
    else
        y = 0;

    printf("demo1: x=%d, y=%d\n", x, y);

    // 书写方式2
    if (x!=0)
        if (x>0) y = 1;
    else y = -1;

    printf("demo2: x=%d, y=%d\n", x, y);
}
