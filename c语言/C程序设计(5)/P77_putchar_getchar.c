#include "stdio.h"

/*
  putchar()��������ַ�, �������һ������, ����ת��Ϊ��ʹ���ַ����Ķ�Ӧ�ַ�
  getchar()�Ӽ��̻����л�ȡһ���ַ�, Enter����
*/

void main(){
    char x, y;
    int z;
    x = getchar();
    y = getchar();
    z = getchar();

    putchar('\n');
    putchar(x);
    putchar(y);
    z += 32;
    putchar(z);
    putchar('\n');
}
