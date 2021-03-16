# include "stdio.h"
# include "stdlib.h"
# include "string.h"

/*
    从键盘输入若干字符(每行长度不等), 输入后把它们存储到一磁盘文件中. 
    在从该文件中读取这些数据, 将其中的小写字母转换成大写字母后显示.
*/

# define STRLEN_LIMIT 256


int main(int args, char * argv[]){
    char * filepath = "./do_not_push_input.txt";
    char string[STRLEN_LIMIT] = {};

    // 获取输入数据, 写入文件
    FILE * fp = NULL;
    if((fp=fopen(filepath, "w"))==NULL){
        puts("文件打开失败.");
        exit(0);
    }
    puts("输入内容(quit退出).");
    while (1){
        fgets(string, STRLEN_LIMIT, stdin);   // 读取每一行, 包含\n, 如果要自己整换行, 用scanf("%s\n", string)
        if (strcmp(string, "quit\n")==0) break;
        fputs(string, fp);    
    }

    puts("\n完成文件输入, 读取文件中内容.");
    if ((fp=freopen(filepath, "r", fp))==NULL){
        puts("文件重新打开失败.");
        exit(0);
    }

    while(!feof(fp)){   // 最后一行使EOF, 算作一行, 内容为EOF, 所以会比预期的多输出一行
        fgets(string, STRLEN_LIMIT, fp);
        for (int i=0; i<strlen(string); i++){
            if ('a'<=string[i] && string[i]<='z'){
                string[i] -= 32;
            }
        }
        printf("%s", string);
    }


    fclose(fp);

    return 0;
}