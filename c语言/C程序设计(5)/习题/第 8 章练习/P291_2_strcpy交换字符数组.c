# include "stdio.h"
# include "string.h"

# define len 64

/*
    int strcmp(const char * __s1, const char * __s2)
    比较字符串1和字符串2
    如果字符串1与字符串2相同, 函数值返回0.
    如果字符串1>字符串2, 则函数值为一个正整数.
    如果字符串1<字符串2, 则函数值为一个负整数.

    char * strcpy(char * __restrict__dest, const char * __restrict__src)
    将字符数组src复制到字符数组dest中

*/


int main(){
    void swap(char *, char *);

    char str1[len], str2[len], str3[len];
    puts("输入三个字符串: ");
    fgets(str1, len, stdin);
    fgets(str2, len, stdin);
    fgets(str3, len, stdin);

    if (strcmp(str1, str2)>0) swap(str1, str2);
    if (strcmp(str1, str3)>0) swap(str1, str3);
    if (strcmp(str2, str3)>0) swap(str2, str3);

    printf("从小到大排序字符串后: \n%s\n%s\n%s\n", str1, str2, str3);
    return 0;
}


void swap(char * p1, char * p2){
    char str[len];
    strcpy(str, p1);
    strcpy(p1, p2);
    strcpy(p2, str);
}