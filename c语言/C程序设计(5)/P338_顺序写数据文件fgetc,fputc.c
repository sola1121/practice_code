#include "stdio.h"
#include "stdlib.h"

/*  
    FILE *fp;
    ...
    fgetc(fp), 从fp指向的文件读入一个字符. 读成功, 带回所读的字符,失败则返回文件结束标志EOF(即-1)
    fputc(ch, fp), 把单个字符ch写到文件指针变量fp所指向的文件中. 输出成功, 返回值就是输出的字符,输出失败, 则返回EOF(即-1)
*/

int main(){
    char ch, filepath[128] = "tempCodeRunnerFile.txt";
    
    FILE * fp;
    if (fp=fopen(filepath, "w") == NULL){
        printf("打开文件失败.\n");
        exit(0);
    }

    printf("请输入一个准备春初到磁盘的字符串(以#结束): ");
    ch = getchar();
    while(ch != '#'){
        fputc(ch, fp);
        putchar(ch);
        ch = getchar();
    }

    fclose(fp);

    putchar(10);   // 向屏幕输出一个换行符

    return 0;
}