#include "stdio.h"

/*
    A->Z   a->z
    B->Y   b->y
    C->X   c->x
    ...
    M->N   m->n
    第i个字母变成第(26-i+1)个字母
    写出编码和解码方法
*/

int main(){
    int j, n;
    char ch[80], tran[80];

    printf("input cipher code: ");
    fgets(ch, 80, stdin);
    printf("\ncipher code: %s", ch);

    // 进行编码
    j = 0;
    while (ch[j] != '\0'){
        if ((ch[j]>='A') && ch[j]<='Z')
            tran[j] = 155-ch[j];
        else if ((ch[j]>='a') && ch[j]<='z')
            tran[j] = 219-ch[j];
        else
            tran[j] = ch[j];
        j++;
    }

    n = j;
    printf("\noriginal text: ");
    for (j=0; j<n; j++)
        putchar(tran[j]);
    printf("\n");

    return 0;
}