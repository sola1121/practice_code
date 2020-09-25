# include "stdio.h"
# include "stdlib.h"
# include "time.h"
# include "string.h"

/*
    用指向指针的指针的方法对n个整数排序并输出. 
    要求将排序单独写成一个函数. n个整数在主函数中输入, 最后在主函数中输出.
*/


# define arr_len 5
# define str_len 32


void out_put(char **pt, int len){
    for (int i=0; i<len; i++)
        printf("%s\n", *(pt+i));
}


void sort_strings(char **pt, int len){
    char * temp = NULL;
    for (int m=0; m<len; m++){
        for (int n=m; n<len; n++){
            if (strcmp(*(pt+m), *(pt+n))>0){
                temp = *(pt+m);
                *(pt+m) = *(pt+n);
                *(pt+n) = temp;
            }
        }
    }
}


int main(){
    int len=0;
    char string[str_len], * array[arr_len];

    // 生成随机字符串
    // srand((unsigned)time(NULL));
    // for (int i=0; i<arr_len; i++){
    //     len = rand()%str_len+1;
    //     for (int count=0; count<len; count++){
    //         *(string+count) = (char) (rand()%75+48);
    //     }
    //     *(string+len) = '\0';
    //     *(array+i) = strdup(string);
    // }

    for (int i=0; i<arr_len; i++){
        printf("输入字符串: ");
        fgets(string, str_len, stdin);
        *(array+i) = strdup(string);
    }

    printf("原始的字符串数组: \n");
    out_put(array, arr_len);

    sort_strings(array, arr_len);
    
    printf("\n排序后的指针数组: \n");
    out_put(array, arr_len);

    return 0;
}