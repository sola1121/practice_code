# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "time.h"
# include "unistd.h"
# include "iso646.h"


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


// 用于生成随机长度的字符串
char * generate_string3(int len){
    char * ret = (char *) malloc(len);
    char ch = '\0', end = '\0';
    for (int i=0; i<len; i++){
        ch = rand()%26 + 97;
        sprintf(ret, "%s%c", ret, ch);   // strcat(ret, &ch);
    }
    ret[len] = '\0';

    return ret;
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


// 将int数值转换为二进制的表现形式输出
void print_int2binary(int num){
   int i;
   for(i = sizeof(int)*8 - 1; i >= 0; i--){
       if((1 << i) & num)
           printf("%c", '1');
       else
           printf("%c", '0');
   }
   putchar('\n');
}


// 动态的创建二维数组, 以int 类型为例
int ** create_matrix(int row, int column){
    int* *matrix = (int**) malloc(sizeof(int*) * row);
    for (int r=0; r<row; r++)
        matrix[r] = (int*) malloc(sizeof(int) * column);

    return matrix;
}


// 输入字符串, 读取一行字符串, 并将多余的行处理
char * gets_s(int n){
    char *ret_value = (char *) malloc(sizeof(char)*n),
         *find;

    fgets(ret_value, n, stdin);
    if (ret_value){
        find = strchr(ret_value, '\n');   // 找到第一个换行
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')   // 处理剩余行
                continue;
    }

    return ret_value;
}