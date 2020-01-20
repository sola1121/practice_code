#include <stdio.h>

void main(){
    int a, b;
    a = b = 1;
    printf("前增a: %d\n", ++a);
    printf("前增b: %d\n", ++b);

    printf("现在的a=%d, b=%d\n\n", a, b);

    a = b = 1;
    printf("后增a: %d\n", a++);
    printf("后增b: %d\n", b++);

    printf("现在的a=%d, b=%d\n", a, b);
}