# include "stdio.h"
# include "stdlib.h"
# include "time.h"
# include "string.h"

/*
    使用多重指针做参数
    输入10个不等长的字符串. 用另一个函数对它们排序. 然后在主函数中输出这10个排列好的字符串
*/


// 使用二重指针指向指针数组
void out_put(char **pt, int len){
    while (len>0){
        printf("%s\n", *pt++);
        len --;
    }
}


// 使用二重指针排列数组
void sort_sentence(char *pt[], int len){
    char * temp;
    for (int m=0; m<len; m++){
        for (int n=m+1; n<len; n++){
            if (strcmp(*(pt+m), *(pt+n)) > 0){
                temp = *(pt+m);
                *(pt+m) = *(pt+n);
                *(pt+n) = temp;
            }
        }
    }
}


int main(){
    char * words = "abcdefghijklmnopqrstuvwxyz",
         sentence[64],
         * sentences[10];
    int len;
    srand((unsigned)time(NULL));
    for (int i=0; i<10; i++){
        len = rand()%62+1;
        for (int count=0; count<len; count++){
            *(sentence+count) = words[rand()%26];
        }
        *(sentence+len) = '\0';
        sentences[i] = strdup(sentence);
    }

    printf("原始字符:\n");
    out_put(sentences, 10);

    sort_sentence(sentences, 10);

    printf("\n排列后的字符:\n");
    out_put(sentences, 10);

    return 0;
}