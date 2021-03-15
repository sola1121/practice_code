# include "stdio.h"
# include "stdlib.h"
# include "string.h"

/*
    输入一个字符串, 将其中的小写字母全部转换为大写字母, 然后输出到一个磁盘文件中保存, 输入字符串以!结束
*/

int main(int args, char *argv[]){

    int i = 0;
    char ch, string[256];
    fgets(string, 256, stdin);

    for (i=0; i<strlen(string); i++){
        ch = *(string+i);
        putchar(ch);
        if ('a' <= ch && ch<='z') ch -= 32;
        *(string+i) = ch;
    }

    puts("输入内容保存到文件 do_not_push.txt中");

    FILE *fp = NULL;
    if ((fp=fopen("./do_not_push.txt", "wb"))==NULL){
        puts("文件打开失败.\n");
        exit(0);
    }
    fputs(string, fp);
    fputc('!', fp);
    fclose(fp);

    return 0;
}