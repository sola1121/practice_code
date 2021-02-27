#include "stdio.h"
#include "stdlib.h"

/*  
    FILE *fp;
    fp = fopen(文件路径, 打开方式)
    fopen(), 打开文件成功将会返回一个指向文件的指针(即文件信息区的起始地址),读取失败返回空指针NULL
    fclose(文件指针), 撤销文件信息区和文件缓冲区, 使文件指针变量不再指向该文件, 也就是文件指针呢变量与文件脱钩
    fgetc(fp), 从fp指向的文件读入一个字符. 读成功, 带回所读的字符,失败则返回文件结束标志EOF(即-1)
    fputc(ch, fp), 把单个字符ch写到文件指针变量fp所指向的文件中. 输出成功, 返回值就是输出的字符,输出失败, 则返回EOF(即-1)
    
    在向文件写数据时, 是先将数据输出到缓冲区, 待缓冲区充满后才正式输出给文件. 
    如果当数据未充满缓冲区程序结束运行, 就有可能使缓冲区中的数据丢失. 使用fclose()的时候, 其先将缓冲区中的数据输出到磁盘, 然后才撤销文件信息区.

    如果在执行中查看输出的文件, 内容还没有被输入文件, 因为还在缓冲区.
*/

int main(){
    char ch, filepath[128] = "tempCodeRunnerFile.txt";
    
    FILE * fp;
    if ((fp=fopen(filepath, "w")) == NULL){   // 打开写文件
        printf("打开文件失败.\n");
        exit(0);
    }

    printf("请输入一个准备存储到磁盘的字符串(以#结束): ");
    ch = getchar();
    while(ch != '#'){
        fputc(ch, fp);   // 向文件缓冲区写入一个字符
        putchar(ch);   // 将输出的字符显示在屏幕上
        ch = getchar();   // 在接收从键盘输入的字符
    }

    fclose(fp);

    putchar(10);   // 向屏幕输出一个换行符

    return 0;
}