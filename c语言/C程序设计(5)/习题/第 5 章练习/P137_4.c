#include "stdio.h"

void main(){
    int ch, words = 0, spaces = 0, numbers = 0, others = 0;
    printf("输入一行字符串: ");
    while ((ch=getchar())!='\n'){
        if (('a'<ch && ch<'z') || ('A'<ch && ch<'Z'))
            words += 1;
        else if (ch = ' ')
            spaces += 1;
        else if ('0'<ch && ch<'9')
            numbers += 1;
        else 
            others += 1;
    }

    printf("输入字母%d, 空格%d, 数字%d, 其他%d\n", words, spaces, numbers, others);
}