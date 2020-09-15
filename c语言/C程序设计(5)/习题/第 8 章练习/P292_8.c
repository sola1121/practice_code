# include "stdio.h"


int main(){
    int letter_capital=0, letter_low=0, spaces=0, numbers=0, others=0;
    char string[64], *pt;

    printf("输入字符: ");
    fgets(string, 64, stdin);   // scanf("%s", )会将空格判断为结束

    pt = string;

    while (*pt!='\0'){
        printf("开始检查字符: %c\n", *pt);
        if (*pt >= 'A' && *pt <='Z') letter_capital++;
        else if (*pt >= 'a' && *pt <= 'z') letter_low++;
        else if (*pt == ' ') spaces++;
        else if (*pt >= '0' && *pt <= '9') numbers++;
        else others ++;
        pt ++;
    }

    printf("所输入字符有大写字母%d, 小写字母%d, 空格%d, 数字%d, 其他%d\n", 
                            letter_capital, letter_low, spaces, numbers, others);
}