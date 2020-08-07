#include "stdio.h"
#include "string.h"

/*
    类型名 * 数组名[数组长度];
*/


void sort_strings(char * name[], int len){   // 接受一个任意长度的指针数组 
    char * temp;
    int m, n, i;
    /* 使用选择排序法, 从小到大排列 */
    for(m=0; m<len-1; m++){   // 遍历数组
        i = m;
        for(n=m+1; n<len; n++)   // 遍历数组
            if (strcmp(name[i], name[n])>0) i=n;   // 字符串进行比较, 若下标i处的字符串大于n处的字符串, 让i=n
        if (i!=m){   // 如果i不等于m, 即比较后, m(i)处的字符串大于n处的字符串, 进行值交换. 注意, 这里交换的是指针指向
            temp = name[m];
            name[m] = name[i];
            name[i] = temp;
        }
    }
}


void print_strings(char * name[], int n){
    int i;
    for(i=0; i<n; i++)
        printf("%s\n", name[i]);   // 按指针数组元素的顺序输出它们所指向的字符串
}


void print_strings2(char *name, int n){
    int i=0;
    char * p;
    p = name[0];

    while(i<n){
        p = *(name+i++);   // 先求*(name+i)的值, 即name[i](这是一个地址), 然后使i自增
        printf("%s\n", p);
    }
}


int main(){
    // 指针数组, 其内容元素是char*, 指向字符串的首字符的地址
    char * name[] = {"Midnight Sun", "Atomic Habits", "FOX", "Just Mercy", "Educated: A Memoir"};

    sort_strings(name, 5);
    print_strings(name, 5);

    return 0;
}