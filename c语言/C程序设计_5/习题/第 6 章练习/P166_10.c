#include "stdio.h"

#define row 3
#define column 80

/*
    有一篇文章, 共有三行文字, 每行有80个字符.
    分别统计出其中英文大写, 小写, 数字, 空格, 以及其它字符个数.
*/


int main(){
    char essay[row][column] = {
        {"Input and Output operations can also be performed in C++ ."},
        {"Streams are handled in the cstdio library as pointers to FILE objects. "},
        {"A pointer to a FILE object uniquely identifies a stream."}
    }, temp;
    int upper_ch = 0, low_ch = 0, Numbers = 0, spaces = 0, others = 0;

    for (int rw=0; rw<row; rw++){
        for (int col=0; essay[rw][col]!='\0'; col++){
            temp = essay[rw][col];
            if ('A'<=temp && temp<='Z')
                ++ upper_ch;
            else if ('a'<=temp && temp<='z')
                ++ low_ch;
            else if ('0'<=temp && temp<='9')
                ++ Numbers;
            else if (temp == ' ')
                ++ spaces;
            else
                ++ others;
        }
    }

    printf("have capital: %d; lowercase: %d; numbers: %d; spaces: %d; others: %d\n", 
            upper_ch, low_ch, Numbers, spaces, others);

    return 0;
}