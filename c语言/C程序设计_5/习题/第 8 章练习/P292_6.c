# include "stdio.h"


# define len 64

int strings_length(char * string){
    int lenght = 0;
    while (*string++!='\0')
        lenght += 1;

    return lenght;
}


int main(){
    char string[len];
    scanf("%s", string);

    printf("所输入的字符串长度为: %d\n", strings_length(string));

    return 0;
}