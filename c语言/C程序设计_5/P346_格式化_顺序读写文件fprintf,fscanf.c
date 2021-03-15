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

    REVIEW: 有趣的是每次生成的随机字符串都是一样的, 那这还能叫随机字符串吗. 你个逗比, 你没有设置srand随机种子

    注意, 格式化scanf()读取时, 如果scanf(stream, "%s,%d\n", string, i); 这之后的%d的数据会读不出来, 会被看做%s的一部分, 赋值给string
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
        fprintf(fp, "%d,%s\n", i, *(input_info+i));   // 格式格式化向文件输出
    }

    fclose(fp);

    puts("\n现在从文件中读出来...\n");
    int *num;
    char string[32];
    if ((fp=fopen(filepath, "r"))==NULL){
        puts("文件打开失败.\n");
        exit(0);
    }

    while(fscanf(fp, "%s", string) != EOF)   // 格式化向文件读取, 这里把整个文件看做一个字符串, 全部读出
        puts(string);

    rewind(fp);

    putchar(10);

    int id=0;
    while (!feof(fp)){
        fscanf(fp, "%d,%s\n,", &id, string);   // 格式化向文件读取, 这里按每行格式读取
        printf("%d,%s\n", id, string);
    }

    fclose(fp);

    return 0;
}