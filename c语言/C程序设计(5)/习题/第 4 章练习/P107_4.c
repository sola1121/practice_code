#include "stdio.h"

int main(){
    int a, b, c;
    printf("����������: ");
    scanf("%d%d%d", &a, &b, &c);

    a = b>a?b:a;
    a = c>a?c:a;
    printf("�������нϴ����: %d\n", a);

    return 0;
}
