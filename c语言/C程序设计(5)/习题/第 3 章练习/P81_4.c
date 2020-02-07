#include "stdio.h"

int main(){
    char c1, c2, *s_num = "c1=%d, c2=%d\n", *c_num = "c1=%c, c2=%c\n";

    c1 = 97, c2 = 98;
    printf(s_num, c1, c2);
    printf(c_num, c1, c2);

    c1 = 197, c2 = 198;
    printf(s_num, c1, c2);
    printf(c_num, c1, c2);

    int c3, c4;
    c3 = 197, c4 = 198;
    printf(s_num, c3, c4);
    printf(c_num, c3, c4);

    return 0;
}