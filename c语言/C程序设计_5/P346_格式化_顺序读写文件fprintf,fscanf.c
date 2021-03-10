#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

/*
    下面二者参数中stream为文件指针, format为格式控制字符串

    int fprintf(FILE * stream, const char * format, ...)
    执行成功则返回写入的字符的个数, 失败则返回负数.

    int fscanf(FILE * stream, const char * format, ...)
    返回参数列表中被成功赋值的参数个数.

    fprintf写入文件,fscanf读出文件与printf写入输出,scanf读出输入 非常相似, 后者就相当于定义了文件指针为stdout和stdin一样, 而前者需要自己指定

    REVIEW: 有趣的是每次生成的随机字符串都是一样的, 那这还能叫随机字符串吗
*/

#define INFO_LEN 32


char * generate_string(){
    int i = 0, length = 0;
    length = rand()%31+1;
    static char string[32];   // 字符串
    while (i<length) {
        string[i] = rand()%26+97;
        i++;
    }
    string[length] = '\0';
    return string;
}


int main(){
    char input_info[INFO_LEN][32], *pt;

    for (int i=0; i<INFO_LEN; i++)
        strcpy(input_info[i], generate_string());
    puts("生成的内容为\n");
    for (int i=0; i<INFO_LEN; i++)
        puts(*(input_info+i));

    FILE *fp;
    char * filepath = "./do_not_push_test.csv";
    puts("\n现在将其输入到文件中...\n");
    if ((fp=fopen(filepath, "w"))==NULL){
        puts("文件开启失败.\n");
        exit(0);
    }

    for (int i=0; i<INFO_LEN; i++){
        fprintf(fp, "%d,%s\n", i, *(input_info+i));
    }

    fclose(fp);

    puts("\n现在从文件中读出来...\n");
    int *num;
    char string[32];
    if ((fp=fopen(filepath, "r"))==NULL){
        puts("文件打开失败.\n");
        exit(0);
    }

    while(fscanf(fp, "%s", string) != EOF)
        puts(string);

    fclose(fp);

    return 0;
}