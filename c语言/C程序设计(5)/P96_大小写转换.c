#include "stdio.h"

int main(){
    char c;
    c = getchar();
    if (c >= 'a' && c <= 'z'){
        printf("�������Сд��ĸ, ת��Ϊ��д: %c\n", c-32);
    } else if (c >= 'A' && c <= 'Z'){
        printf("������Ǵ�д��ĸ, ת��ΪСд: %c\n", c+32);
    } else {
        printf("��Ӧ������һ����ĸ.\n");
    }

    c>='A'&&c<='Z' ? printf("�Ǵ�д��ĸ.\n") : printf("��Сд��ĸ.\n");   // ֻ��������дһ�����ʽ
    return 0;
}
