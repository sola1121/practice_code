# include "stdio.h"

/*
    数组b(复制到的数组)长度大于数组a(源数组) 
    在完成复制后, 为其添加一个\0, 如果没有添加的话, 那么剩下的也将会由%s输出.
    使用%c遍历, 就可以将长度内所有元素输出

    编译系统是把字符数组名按指针变量处理的, 只是表示形式不同

    实参: 字符数组名 -> 形参: 字符数组名
    实参: 字符数组名 -> 形参: 字符指针变量
    实参; 字符指针变量 -> 形参: 字符数组名
    实参: 字符指针变量 -> 形参: 字符指针变量
*/

void copy_string(char sour[], char dest[]){   // 形参为字符数组
    int i = 0;
    while (sour[i]!='\0'){
        dest[i] = sour[i];
        i++;
    }
    dest[i] = '\0';
}


void copy_string2(char *sour, char *dest){   // 形参为字符指针变量
    for (; *sour!='\0'; sour++, dest++)
        *dest = *sour;
    *dest = '\0';
}


int main(){
    char a[] = "Hello, World.", 
         b[] = "Hello, World, too.";

    printf("a 地址 值\n  └%p %s\n", a, a);
    printf("b 地址 值\n  └%p %s\n", b, b);
    copy_string(a, b);
    printf("a 地址 值\n  └%p %s\n", a, a);
    printf("b 地址 值\n  └%p %s\n", b, b);

    char c[] = "Hello, World.",
         d[] = "Hello, World, too.";

    char *from = c, 
         *to = d;   // from指向c数组的首元素, to指向d数组的首元素

    printf("\n\nfrom 地址 值\n  └%p %s\n", from, from);
    printf("to 地址 值\n  └%p %s\n", to, to);
    copy_string(from, to);
    printf("c 地址 值\n  └%p %s\n", c, c);
    printf("d 地址 值\n  └%p %s\n", d, d);

    char *e = "Hello, World.",
         f[] = "Hello, World, too.";
    
    char *p = f;   // 使指针变量p指向f数组首元素

    printf("\n\ne 地址 值\n  └%p %s\n", e, e);
    printf("p 地址 值\n  └%p %s\n", p, p);
    copy_string(e, p);
    printf("e 地址 值\n  └%p %s\n", e, e);
    printf("f 地址 值\n  └%p %s\n", f, f);


    return 0;
}


/* 更加简单的遍历
   利用自增加运算符
 */

void copy_string_1_1(char *source, char *destination){
    while((*destination = *source) !='\0')
        *destination++; *source++;
}

void copy_string_1_2(char *source, char *destination){
    while((*destination++ = *source++) != '\0');
}

void copy_string_2_1(char *source, char *destination){
    while(*source != '\0')
        *destination++ = *source++;
    *destination = '\0'
}

void copy_string_2_2(char *source, char *destination){
    while(*source)   // '\0' 在ASCII中的值为0
        *destination++ = *source++;
    *destination = '\0';
}

void copy_string_2_3(char *source, char *destination){
    while(*destination++ = *source++);   // 等价于 while((*destination++ = *source++) != '\0');
}

void copy_string_2_4(char *source, char *destination){
    for(;*destination++ = *source++;);   // 等价于 for(;(*destination++ = *source++) != '\0');
}

void copy_string_3_1(char source[], char destination[]){
    char *p1, *p2;
    p1 = source, p2 = destination;
    while((*p2++ = *p2++) != '\0');
}