#include "stdio.h"
#include "uchar.h"
#include "wchar.h"

#define length 64

void str_print(unsigned int *str){
    int n = 0;
    while (1){
        if (str[n] != '\0')
            putwchar(str[n]);
        else {
            printf("\n");
            break;
        }
        n += 1;
    }
}

void main(){
    char str_0[length] = "普通数组字符, 可以不用分开写.\n";   // 或 {"内容"}; 的形式
    char str_1[length] = {'0'};
    // 长字符, 16位的占两个字节, 32位的占4个字节, 可以支持Unicode字符集, uchar.h中char_t的只单纯的是unsigned int 的别名
    char16_t ch_16_t = u'u';
    char32_t ch_32_t = U'U';
    char32_t str_32_t[length] = U"char32长字符类型数组";

    wchar_t ch_wide_t = L'L';
    wchar_t str_wide_t[length] = L"wide长字符类型数组.";

    printf("%s", str_0);
    printf("长字符类型 (%d ~ %d) %c %c %c\n", WCHAR_MIN, WCHAR_MAX, ch_16_t, ch_32_t, ch_wide_t);
    printf("长字符类型指针(数组), 无法用%%s进行输出, 用%%ls\n");

    size_t len1 = sizeof(str_32_t[0]), len2 = sizeof(str_wide_t[0]), len3 = sizeof(ch_16_t);
    printf("char16字节数: %ld; char32字节数: %ld; wchar字节数: %ld \n", len3, len1, len2);

    str_print(str_32_t);
    str_print(str_wide_t);
    wprintf(L"wideprintf: %ls\n", str_wide_t);

    scanf("%s", str_1);   // 因为数组本生就是指针类型, 不需要在转化为地址传入了.
    /* scanf 会把空格看做是\0, 这样, 如果输入之中用空格, 就会被截断. */
    printf("刚才输入: %s\n", str_1);
}