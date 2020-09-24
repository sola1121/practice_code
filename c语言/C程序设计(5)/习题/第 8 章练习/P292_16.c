# include "stdio.h"
# include "stdlib.h"
# include "time.h"
# include "string.h"
# include "math.h"

/*
    将字符串中出现的连续的数字作为一个整数保存于一个数组, 并输出

    主要使用stdlib.h中的atoi(const char * s)将符合的字符串部分转换为整型
*/

void extract(int array[], char * string, int str_len){
    // count用于arrary, 用于记录保存到了第几个; digit记录有几位; is_num配合start, 是否其已经记录了; start记录数字的开始位置; get_num提取到的数字
    int count=0, digit=0, is_num = 0, start=-1;
    unsigned int get_num=0;
    for (int i=0; i<str_len; i++){
        if (*(string+i) == '\0') break;
        // printf("检查单个字符: %c\n", *(string+i));
        if (*(string+i) >= '0' && *(string+i) <= '9'){
            if (is_num==0) {
                start = i;
                is_num += 1;
            }
            digit += 1;
        } else {
            if (digit >= 2){
                get_num = atoi(string+start);
                printf("转换为的数字: %d.\n", get_num);
                *(array+count) = get_num;
                count ++;
            }
            // 重置
            get_num = 0;
            start = -1;
            is_num = 0;
            digit = 0;
        }
    }
    printf("总共获得 %d 个两位及以上的整数.\n", count);
}


int main(){
    srand((unsigned)time(NULL));
    int str_len = rand()%256, words_len, rnd_num, array[128];
    char * words = "0123456789abcdefghijklmnopqrstuvwxyz <>?,./;':\"[]\\{}|-=_+`~!@#$%^&*()",
         string[str_len];
    words_len = strlen(words);
    printf("字符串长度: %d\n", str_len);

    for (int i=0; i<str_len; i++){
        rnd_num = rand()%(words_len*2);
        if (rnd_num > words_len) rnd_num = rand()%10;   // 提高出现数字的概率
        *(string+i) = *(words+rnd_num);
    }
    printf("生成的字符串: %s\n\n", string);

    extract(array, string, str_len);

    for (int i=0; i<128; i++){
        if (array[i] ==0) break;
        else printf("%d  ", array[i]);
    }
    printf("\n");

    return 0;
}