# include "stdio.h"
# include "string.h"
# include "time.h"
# include "unistd.h"


// 用于生成随机长度字符串, 使用strcpy(目标, generate_string())
char * generate_string(){
    int i = 0, length = 0;
    length = rand()%31 + 1;   // 随机长度
    static char result[32];   // 字符串
    while (i<length) {
        result[i] = rand()%26 + 97;
        i++;
    }
    result[length] = '\0';
    return result;
}


// 用于生成指定长度的随机字符串, 使用strcpy(目标, generate_string(8))
char * generate_string2(int len){
    char * result = (char *) malloc(sizeof(char)*256);   // 字符串
    char ch = '\0';
    for (int i=0; i<len; i++){
        ch = rand()%26 + 97;
        sprintf(result, "%s%c", result, ch);   // strcat(result, &ch);
    }
    result[len] = '\0';

    return result;
}


// TODO: 使用指针指向函数, 可以通过该指针调用不同的函数

// TODO: 通过char*指针, 输出存储char*(即字符串)的数组


// DEBUG 返回数组长度
int array_length(void *array){
    return sizeof(array)/sizeof(array[0]);
}


// MARK 还没测试过, 估计不行. 用来创建一个进程执行的
void multi_process(int (*func)(int argc, char *argv[]), int argc, char *argv[]){
    int pid=-1;
    pid = fork();
    if (pid == 0){
        (*func)(argc, argv);
    } else if (pid == -1){
        puts("Error: 进程创建失败.\n");
        exit(0);
    }
}


// 返回输入的字符, 使用 strcpy(目标, input_string());
char * input_string(){
    static char result[512];
    printf("输入字符: ");
    scanf("%s", result);
    getchar();   //用来消化最后输入的回车符

    return result;
}
