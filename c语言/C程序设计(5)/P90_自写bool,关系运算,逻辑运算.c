#include "stdio.h"

typedef int bool;
#define True 1
#define False 0

#define and &&
#define or ||
#define not !

int main(){
    bool t = True, f = False;

    printf("True: %d, False: %d \n", True, False);

    if (True) printf("�ǵ�,�Զ����True������.\n");
    if (!False) printf("�ǵ�,�Զ����False������.\n");

    if (t and t) printf("True and True �ɹ�ִ��.\n");
    if (t or f) printf("True or False �ɹ�ִ��.\n");
    if (not f) printf("not False �ɹ�ִ��.\n");

    //���ȼ�: �߼���(!) > ��ϵ����� > ��������� > �߼���(&&) �߼���(||) > ��ֵ�����
    printf("%d\n", 4&&4-!4);
    return 0;
}
