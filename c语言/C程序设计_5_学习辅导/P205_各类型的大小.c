# include "stdio.h"
# include "limits.h"


int main(int args, int argv[]){
    char * format = "%s    %d    %d    %d\n";
    puts("类型      字节数     最小值     最大值");
    printf(format, "char", 1, CHAR_MIN, CHAR_MAX);
    printf(format, "short", 2, SHRT_MIN, SHRT_MAX);
    printf(format, "int", 4, INT_MIN, INT_MAX);
    format = "%s    %d    %ld    %ld\n";
    printf(format, "long long", 8, LLONG_MIN, LLONG_MAX);
    format = "%s    %d    %le    %le\n";
    printf(format, "float", 4, __FLT_MIN__, __FLT_MAX__);
    printf(format, "double", 8, __DBL_MIN__, __DBL_MAX__);
    format = "%s    %d    %lle    %lle\n";
    printf(format, "long double", 12, __LDBL_MIN__, __LDBL_MAX__);

    return 0;
}

/*
类型      字节数     最小值     最大值
char        1       -128        127
short       2       -32768      32767
int         4    -2147483648    2147483647
long long   8    -9223372036854775808    9223372036854775807
float       4    1.175494e-38    3.402823e+38
double      8    2.225074e-308   1.797693e+308
long double 12   3.362103e-4932  1.189731e+4932

*/