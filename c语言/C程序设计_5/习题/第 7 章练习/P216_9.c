#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define length 64

static int words=0, numbers=0, spaces=0, others=0;

void statistics(char *str){
    for (int i=0; str[i]!='\0'; i++){
        if ('a'<=str[i] && str[i]<='z' || 'A'<=str[i] && str[i]<='Z')   // or 优先级低于 and
            words += 1;
        else if ('0'<=str[i] && str[i]<='9')
            numbers += 1;
        else if (str[i]==' ')
            spaces += 1;
        else
            others += 1;
    }
}


void main(){
    srand((unsigned) time(NULL));
    int rand_int = 0;

    char str[length] = {'0'};
    for (int i=0; i<length; i++){
        rand_int = rand() % 128;
        if (rand_int<14) rand_int =32;
        str[i] = (char) rand_int;
    }

    printf("随机生成字符串: \n%s\n", str);

    statistics(str);
    printf("统计数据, 字母: %d, 数字: %d, 空格: %d, 其它: %d\n", words, numbers, spaces, others);
}