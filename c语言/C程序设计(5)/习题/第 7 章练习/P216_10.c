#include "stdio.h"
#include "string.h"

/*
    输出最长字母
*/

struct Words{
    int len;
    char word[128];
} word_record = {0, ' '};


int is_word(char ch){
    int bool_=0;
    if ('a'<=ch && ch<='z' || 'A'<=ch && 'Z'<=ch)
        bool_ = 1;
    return bool_;
}


int is_space(char ch){
    int bool_=0;
    if (ch == ' ')
        bool_ = 1;
    return bool_;
}


void max_len_word(char *str){
    for (int i=0; i<strlen(str); i++){

        if (is_word(str[i])){
            for (int m=i; m<strlen(str); m++){
                if (is_space(str[m])){
                    
                    if (word_record.len < m-i){
                        word_record.len = m-i;
                        int count = 0;
                        for (int start=i; start<m; start++){
                            word_record.word[count] = str[0];
                            count++;
                        }
                    }

                }
            }
        }
        
    }
}


int main(){
    char *string = "I said  Hello to the hell where human live.";

    max_len_word(string);
    printf("%d, %s\n", word_record.len, word_record.word);

    return 0;
}