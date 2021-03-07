#include "stdio.h"

const int head_row = 4;
const int tail_row = 3;

int main(){
    char c = '*', s = ' ';

    for (int row=head_row; row>0; row--){   // 4, 3, 2, 1
        for (int space=row-1; space>0; space--)   // space需要输出三行 3 2 1
            printf("%c", s);
        for (int asterisk=row-2; asterisk<3; asterisk ++)   // *需要输出四行, 每行递增 1 2 3 4
            printf("%c", c);
        for (int asterisk=row-1; asterisk<3; asterisk ++)   // 输出同行的右边的一半 0 1 2 3
            printf("%c", c);
        printf("\n");
    }

    for (int row=1; row<=tail_row; row++){   // 1, 2, 3
        for (int space=0; space<row; space++)   // space需要输出三行 1 2 3
            printf("%c", s);
        for (int asterisk=3; asterisk>=row; asterisk--)   // *需要输出三行 3 2 1
            printf("%c", c);
        for (int asterisk=2; asterisk>=row; asterisk--)   // 输出同行右边的一半 2 1 0
            printf("%c", c);
        printf("\n");
    }

    return 0;
}