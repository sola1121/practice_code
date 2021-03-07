# include "stdio.h"
# include "string.h"

# define len 64


void copy_string_from(char * string, char * new_string, int num){
    if (num>len || num<0) return ;
    for(; *(string+num)!='\0'; new_string++, num++){
        *new_string = *(string+num);
    }
    *new_string = '\0';
}


int main(){
    char string[len], new_string[len];
    int start;
    printf("输入字符串:");
    scanf("%s", string);
    printf("截取下标:");
    scanf("%d", &start);

    copy_string_from(string, new_string, start);

    printf("截取后: %s\n", new_string);

    return 0;
}