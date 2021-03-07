# include "stdio.h"


int main(){
    char ch[] = "Hello, World. Array", ch1[20], *ch_arr[20], *ch_p1, *ch_p2;
    char *s1 = "Hello, World.", *s2, *s3, *s4;
    s2 = "Hello, World2.";
    // *s3 = "Hello, World3.";   这样是不行的, 会造成segmentation fault
    s4 = ch;   // 指针赋值字符串第一个字符地址, 地址相同

    printf("%s, 地址: %p\n", s1, s1);
    printf("%s, 地址: %p\n", s2, s2);
    printf("%s, 地址: %p\n", s4, s4);
    printf("%s, 地址: %p\n", ch, ch);   // *s4 和 ch[] 都可以使用%s

    // 使用数组遍历字符串
    for(int i=0; ch[i]!='\0'; i++)
        printf("%c", ch[i]);
    printf("\n   └使用数组遍历\n");

    // 使用指针遍历字符串
    for(int i=0; *(s4+i)!='\0'; i++)
        printf("%c", *(s4+i));
    printf("\n   └使用指针遍历\n\n\n");

    // 使用遍历值赋值字符串, 看是否与源地址相同, 将会值复制, 地址是不同的
    int i;
    for(i=0; ch[i]!='\0'; i++)
        ch1[i] = ch[i];
    ch[i] = '\0';   // 不要忘了最后的结束符
    printf("%s, 地址: %p\n", ch1, ch1);

    // 通过遍值赋值字符串, 看是否与源地址相同, 
    ch_p1 = ch1, ch_p2 = ch_arr;   // 中间工具, 用来挨个对源中的数据进行指代
    for(; *(ch_p1)!='\0'; ch_p2++, ch_p1++)
        * ch_p2 = *ch_p1;
    * ch_p2 = '\0';
    printf("%s, 地址: %p\n", ch_arr, ch_arr);   // 因为ch_arr指向的是赋值后的源的头, 这里用ch_arr

    return 0;
}