# include "stdio.h"
# include "string.h"
# include "time.h"


// 用于生成随机字符串
char * generate_string(){
    // 使用strcpy(目标, generate_string())
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