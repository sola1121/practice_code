#include "stdio.h"
#include "string.h"


void main(){
    int return_code = 0;
    char *__cut__ = "=========================\n";
    char str1[] = "First String.", str2[] = "Second String", *str3, str4[1024]={""};

    // 输出字符串
    return_code = puts(str1);
    printf("puts返回 %d, 为字符串的总长度, 包含\\0 \n", return_code);

    printf("%s进行字符串输入\n", __cut__);
    // 输入字符串
    // 系统不推荐 gets(str), 其不检查字符串长度
    str3 = fgets(str1, 18, stdin);   // 会跟一个\n, 就是按enter键的时候来的
    puts(str1);
    printf("fgets返回的char* %s - %p \n", str3, str3);

    printf("%s进行字符串连接\n", __cut__);
    // 字符串连接 string catenate
    str3 = strcat(str2, str2);
    puts(str3);
    printf("strcat返回的char* %s - %p\n", str3, str3);
    
    printf("%s进行字符串复制\n", __cut__);
    // 字符串复制
    str3 = strcpy(str4, str1);
    puts(str4);
    printf("strcpy返回的char* %s - %p\n", str3, str3);
    str3 = strncpy(str4, str2, 3);
    
    // 字符串比较, 大于返回正整数, 等于返回0, 小于返回负整数
    printf("%s进行字符串比较\n", __cut__);
    printf("%s 比较 %s\n", str1, str2);
    return_code = strcmp(str1, str2);
    printf("strcmp返回 %d \n", return_code);
    return_code = strncmp(str1, str2, 3);
    printf("strncmp返回 %d \n", return_code);

    // 字符串长度
    printf("%s进行字符串长度\n", __cut__);
    return_code = strlen(str1);
    printf("字符串 %s 的长度是 %d \n", str1, return_code);   // 实际字符串长度, 不包含\0

    /* gcc的标准库中并不支持, 使用ctype.h 中的toupper 或 tolower 能将单个字符转换为大写 或 小写返回*/
    // printf("%s进行大小写转换\n", __cut__);
    // // 转换为大写
    // str3 = strupr("abc");
    // printf("strupr的返回值 %s\n", str3);

    // // 转换为小写
    // str3 = strlwr("ABC");
    // printf("strlwr的返回值 %s\n", str3);
}