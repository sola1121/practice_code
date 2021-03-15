# include "stdio.h"
# include "stdlib.h"

/*
    int feof(FILE *stream) 判断当前文件是否遇到文件结束标志
    如果文件尾读出, 返回1(真); 如果没有读出, 返回0(假)

    在<stdio.h>中#define EOF (-1), 可以直接使用 content == EOF 来判断是否读取完毕

    注意, 实际操作中feof() 在循环判断中总会多一位. 比如使用while(!feof(stream)) 会多循环操作一次
*/


int main(){

    char *srcFilename = "C_log.svg", *dstFilename =  "do_not_push_C_log(2).svg", ch;
    FILE *src, *dst;

    if((src = fopen(srcFilename, "rb")) == NULL){
        puts("源文件读取失败.\n");
        exit(0);
    }

    if((dst = fopen(dstFilename, "wb")) == NULL){
        puts("目标文件打开失败.\n");
        exit(0);
    }

    // 进行复制文件, 就是挨个挨个将一个文件中的字符读取写入到另一个文件中去
    ch = fgetc(src);   // int fgetc(FILE *__stream)
    while (!feof(src)){
        fputc(ch, dst);   // int fputc(int __c, FILE *__stream)
        putchar(ch);   // 看看当前读取了什么到目标文件
        ch = fgetc(src);
    }

    putchar(10);   // 显示完全部字符后换行
    fclose(src);
    fclose(dst);

    return 0;
}