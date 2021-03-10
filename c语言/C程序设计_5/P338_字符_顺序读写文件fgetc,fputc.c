#include "stdio.h"
#include "stdlib.h"

/*  
    FILE *fopen(const char *filename, const char *modes)
    打开文件成功将会返回一个指向文件的指针(即文件信息区的起始地址),读取失败返回空指针NULL

    int fclose(FILE * stream)
    撤销文件信息区和文件缓冲区, 使文件指针变量不再指向该文件, 也就是文件指针变量与文件脱钩

    常用示例:
    FILE *fp;
    if ((fp = fopen(文件路径, 打开方式)) == NULL){
        printf("Error, can't open file.");
        exit(0);
    }
    ...
    fclose(fp);

    int fgetc(FILE *stream)
    从steam指向的文件读入一个字符. 读成功, 带回所读的字符,失败则返回文件结束标志EOF(即-1)

    int fputc(int c, FILE *stream)
    把单个字符c写到文件指针变量stream所指向的文件中. 输出成功, 返回值就是输出的字符,输出失败, 则返回EOF(即-1)
    
    在向文件写数据时, 是先将数据输出到缓冲区, 待缓冲区充满后才正式输出给文件. 
    如果当数据未充满缓冲区程序结束运行, 就有可能使缓冲区中的数据丢失. 使用fclose()的时候, 其先将缓冲区中的数据输出到磁盘, 然后才撤销文件信息区.

    如果在执行中查看输出的文件, 内容还没有被输入文件, 因为还在缓冲区.

    int fgetc(FILE *stream)和int getc(FILE *stream)是一样的
    int fputc(int c, FILE *stream)和int putc(int c, FILE * stream)是一样的

    void exit(int status) 方法在<stdlib.h>中提供
*/

int main(){
    char ch, filepath[128] = "do_not_push_datatest.txt";
    
    FILE * fp;
    if ((fp=fopen(filepath, "w")) == NULL){   // 打开写文件
        puts("打开文件失败.\n");
        exit(0);
    }

    puts("请输入一个准备存储到磁盘的字符串(以#结束): ");
    ch = getchar();
    while(ch != '#'){
        putchar(ch);   // 将输出的字符显示在屏幕上
        fputc(ch, fp);   // 向文件缓冲区写入一个字符
        ch = getchar();   // 在接收从键盘输入的字符
    }

    fclose(fp);
    putchar(10);   // 向屏幕输出一个换行符

    puts("\n查看文件中内容\n");

    if ((fp=fopen(filepath, "r")) == NULL){
        puts("文件打开失败.\n");
        exit(0);
    }

    while (ch!=-1){   // EOF = -1, 这里判断是不是文件结尾符
        ch = fgetc(fp);
        putchar(ch);
    }

    fclose(fp);

    return 0;
}