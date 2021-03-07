#include "stdio.h"
#include "string.h"

/*
    输出最长字母
*/


int alphabetic(char c){
    if ((c>='a' && c<='z') || (c>='A' && c<='z'))
        return 1;
    else 
        return 0;
}


int longest(char *string){
    int len=0, i, length=0, flag=1, place=0, point;
    for (i=0; i<=strlen(string); i++)
        if (alphabetic(string[i]))   // 当遍历到的是字母的时候
            if (flag){
                point = i;   // 记录单词位置
                flag = 0;
            } else
                len ++;   // len记录当前单词的长度
        else {                       // 当遍历到的不是字母的时候
            flag = 1;
            if (len>=length){   // length记录最长的
                length = len;
                place = point;
                len=0;
            }
        }
    return place;
}


int main(){
    int i;
    char line[100];

    printf("输入内容: ");
    fgets(line, 100, stdin);

    printf("最长的单词是: ");
    for (i=longest(line); alphabetic(line[i]); i++)
        printf("%c", line[i]);

    printf("\n");
    return 0;
}