# include "stdio.h"
# include "stdlib.h"
# include "time.h"
# include "string.h"

/*  
    使用指针数组作为参数
    输入10个等长的字符串. 用另一个函数对它们排序. 然后在主函数中输出这10个排列好的字符串
*/


// 输出字符串数组
void out_put(char * pt[10], int len){
    for (int i=0; i<len; i++)
        printf("%s\n", pt[i]);
}


// 进行字符串的排列
void sort_sentence(char *pt[10], int len){
    char * temp = NULL;
    for (int m=0; m<len; m++){
        for (int n=m+1; n<len; n++){
            if (strcmp(*(pt+m), *(pt+n)) > 0){
                temp = *(pt+n);
                * (pt+n) = *(pt+m);
                * (pt+m) = temp;
            }
        }
    }
}


int main(){
    char * words = "abcdefghijklmnopqrstuvwxyz",
         sentence[10],
         * sentences[10];
    srand((unsigned)time(NULL));
    for (int i=0; i<10; i++){
        for (int count=0; count<10; count++){
            sentence[count] = words[rand()%26];
        }
        sentences[i] = strdup(sentence);   // 使用strdup来将字符串复制到新的地址
    }
    
    printf("原始字符串:\n");
    out_put(sentences, 10);

    sort_sentence(sentences, 10);

    printf("\n排序后的字符串:\n");
    out_put(sentences, 10);

    return 0;
}