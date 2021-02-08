# include "stdio.h"
# include "string.h"
# include "time.h"


// 用于生成随机字符串, 使用strcpy(目标, generate_string())
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


// 返回输入的字符, 使用 strcpy(目标, input_string());
char * input_string(){
    static char result[512];
    printf("输入字符: ");
    scanf("%s", result);
    getchar();   //用来消化最后输入的回车符

    return result;
}
