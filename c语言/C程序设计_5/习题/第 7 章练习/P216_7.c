#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define length 64

/*
    将字符串中的元音字母复制出来放在另一个字符串中
*/

void extract_vowel(char *string){
    char *vowels = "aeiouAEIOU";
    for (int m=0; string[m]!='\0'; m++){
        for (int n=0; vowels[n]!='\0'; n++){
            if (string[m] == vowels[n]){
                printf("%c ", string[m]);
            }
        }
    }
    printf("\n");
}

void main(){
    srand((unsigned) time(NULL));
    char string[length] = {"0"}, 
         words[53] = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i=0; i<=length; i++){
        string[i] = words[(int) (rand()%53)];
    }

    printf("%s\n", string);

    printf("输出其中元音字母:\n");
    extract_vowel(string);
}  