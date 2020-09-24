# include "stdio.h"


/*
    模拟strcmp
*/


int strcmp1(char *pt1, char *pt2){
    int result=0;
    while (*pt1!='\0' && *pt2!='\0'){
        if (*pt1 - *pt2 == 0){
            pt1 ++;
            pt2 ++;
        } else {
            return (int)*pt1 - (int)*pt2;
        }
    }
    if (*pt1=='\0') return -1;
    else return 1;
    return 0;
}


int main(){
    char * s1 = "Hello.", * s2 = "Hello.";

    printf("字符串比较值: %d\n", strcmp1(s1, s2));

    return 0;
}