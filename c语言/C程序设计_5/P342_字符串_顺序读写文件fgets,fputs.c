#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

/*
    char * fgets(char * str, int n, FILE * fp), 从fp指向的文件中读入n-1个字符, 赋予str, 并补足'\0'
                                                注意, 之后其还会返回str数组首元素的地址. 无内容则返回NULL.
    如果在读完n-1个字符之前遇到换行符'\n'或文件结束符EOF, 读入结束, 所遇到的换行符'\n'也作为一个字符读入.
    也就是fgets每次只读取一行内容.

    int fputs(char * str, FILE * fp), 将str所指向的字符串输出到fp所指向的文件中. 输出是成功,返回0(在本人机器上是1),失败返回EOF.
    str可以是字符串常量, 字符数组名, 字符型指针. 字符串末尾的'\0'不输出.

    fgets与fputs同int gets()与int puts(const char *s)相似, 前者是从文件中读和写, 后者是从stdin和stdout中获取与输出

    还有个 void perror(const char *s)向stderr中输出
*/


void checkSuccess(int num, char * hint){
    if (num == 1) printf("操作成功, %s\n", hint);
    else printf("操作失败, %s\n", hint);
}


int main(){
    char str_array[3][16], temp[16];
    int isSuccess = 1;

    puts("输入字符串:");
    for(int i=0; i<3; i++)
        fgets(str_array[i], 16, stdin);   // 使用fgets从stdin向str_array数组传入字符串, 注意fgets会将\n也读入, 也就是只能按行读

    // 选择法对字符串排序
    for(int m=0; m<3; m++){   
        for (int n=m+1; n<3; n++){
            if (strcmp(str_array[m], str_array[n])>0){
                strcpy(temp, str_array[m]);
                strcpy(str_array[m], str_array[n]);
                strcpy(str_array[n], temp);
            }
        }
    }
    puts("当前排序的字符串为");
    for (int i=0; i<3; i++){
        printf("%s", str_array[i]);
    }

    FILE *fp;
    if ((fp=fopen("tempCodeRunnerFile.txt", "w"))==NULL){   // 打开文件
        puts("文件打开错误.");
        exit(0);
    }

    printf("\n同时输出到stdout和文件中, 排序后的字符串为\n");
    for(int i=0; i<3; i++){
        isSuccess = fputs(str_array[i], fp);   // 向磁盘文件写一个字符串
        checkSuccess(isSuccess, "写入字符串");       
        isSuccess = fputs("\n", fp);   // 写入字符串后写一个换行符, 这里其实多写了个换行符, 因为使用fgets接收stdin输入的时候就收了一个换行
        checkSuccess(isSuccess, "写入换行");
        puts(str_array[i]);
    }
    fclose(fp);

    int isOpened = 0, pid = -1;
    char output_str[16];
    puts("\n文件中的内容如下");
    if ((fp = fopen("tempCodeRunnerFile.txt", "r")) == NULL){
        puts("开启文件出错.");
        exit(0);
    }
    puts("\n现在来看看文件, 打开文件");
    pid = fork();   // 创建一个进程, 成功返回0, 此时执行该进程, -1错误. 若返回进程id, 则执行的使父进程
    switch(pid){
        case 0:   // 子进程执行部分
            isOpened = system("xed ./tempCodeRunnerFile.txt");
            if (isOpened == 0) printf("\n文件开启成功");
            break;
        case -1:
            perror("进程创建错误.\n");   // stdio.h中, 使用stderr打印错误
            break;
        default:   // 父进程执行部分
            while(fgets(output_str, 16, fp) != NULL){   // 读取在fp指向文件缓冲区的内容
                printf("%s", output_str);
            }    
    }

    fclose(fp);

    return 0;
}