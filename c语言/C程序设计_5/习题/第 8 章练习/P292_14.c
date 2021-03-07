# include "stdio.h"
# include "stdlib.h"
# include "time.h"
# include "string.h"

# define No 8


void out_put(char **pt, int len){
    for (int i=0; i<len; i++)
        printf("%s\n", *(pt+i));
}


// 将输入时顺序逆序排序
void reverse_strings(char *pt[], int len){
    char * temp;
    for (int i=0; i<(int)len/2; i++){
        temp = *(pt+len-1-i);
        *(pt+len-1-i) = *(pt+i);
        *(pt+i) = temp;
    }
}


int main(){
    char * words = "abcdefghijklmnopqtstuvwxyz",
         string[64],
         * strings[No];
    int len;
    srand((unsigned)time(NULL));
    for (int i=0; i<No; i++){
        len = rand()%62+1;
        for (int count=0; count<len; count++){
            *(string+count) = words[rand()%26];
        }
        *(string+len) = '\0';
        *(strings+i) = strdup(string);
    }

    printf("原字符串:\n");
    out_put(strings, No);

    reverse_strings(strings, No);

    printf("\n倒转后的字符串:\n");
    out_put(strings, No);

    return 0;
}