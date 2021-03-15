# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "time.h"
# include "unistd.h"

/* 
    两个磁盘文件A,B, 各存放一行字母, 今要求把这两个文件中的信息合并(按字母顺序排列),输出到一个新的文件中去
*/

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


int main(int args, char * argv[]){
    srand((unsigned)time(NULL));

    // 先生成A, B这两个文件, 向其中加入字符
    char A_str[32] = {}, B_str[32] = {};
    strcpy(A_str, generate_string()), strcpy(B_str, generate_string());

    FILE * A_fp = NULL, *B_fp = NULL;
    if ((A_fp=fopen("./do_not_push_A.txt", "rw"))==NULL || \
        (B_fp=fopen("./do_not_push_B.txt", "rw"))==NULL){
        puts("文件打开失败.\n");
        exit(0);
    }
    fputs(A_str, A_fp), fputs(B_str, B_fp);

    rewind(A_fp), rewind(B_fp);

    // 拼接C的内容
    char A_str1[32] = {}, B_str1[32] = {}, C_str[72] = {};
    fgets(A_str1, 32, A_fp), fgets(B_str1, 32, B_fp);
    puts(A_str1), puts(B_str1);

    strcat(C_str, A_str1), strcat(C_str, B_str1);

    printf("组合的字符\n%s\n", C_str);

    // 对C进行排序
    char temp = '\0';
    for (int m = 0; m<strlen(C_str); m++){
        for (int n = m+1; n<strlen(C_str); n++){
            if (*(C_str+m) > *(C_str+n)){
                temp = *(C_str+n);
                *(C_str+n) = *(C_str+m);
                *(C_str+m) = temp;
            }
        }
    }
    printf("排序好的C: \n%s\n", C_str);

    // 将C放入文件, 并打开查看
    puts("\n将C放入文件");
    FILE *C_fp = NULL;
    if ((C_fp=fopen("./do_not_push_C.txt", "w"))==NULL){
        puts("文件打开失败.\n");
        exit(0);
    }
    fwrite(C_str, sizeof(char), strlen(C_str), C_fp);

    int pid = 0;
    pid = fork();
    if (pid == -1){
        fputs("ERROR! 进程创建失败.\n", stderr);
        exit(0);
    } else if (pid==0){
        system("xed ./do_not_push_C.txt");
    }

    fclose(A_fp), fclose(B_fp), fclose(C_fp);

    return 0;
}