# include "stdio.h"


int main(int args, char * argv){
    int a = 1, b = 1;

    puts("行排, 全部打印");

    for (a=1; a<=9; a++){
        for (b=1; b<=9; b++){
            printf("%d * %d = %2d   ", a, b, a*b);
        }
        putchar('\n');
    }

    puts("\n以行排的乘法表");

    for (a=1; a<=9; a++){
        for (b=a; b<=9; b++){
            printf("%d * %d = %2d   ", a, b, a*b);
        }
        putchar('\n');
    }

    puts("\n以行排颠倒");

    for (a=1; a<=9; a++){
        // 打印占位的, 可以全部使用空格
        for (b=1; b<=9; b++){
            if (b<a)
                printf("0 * 0 = %2d   ", 0);
            else 
                printf("%d * %d = %2d   ", a, b, a*b);
        }
        putchar('\n');
    }


    puts("\n列排, 全部打印");

    for (a=1; a<=9; a++){
        for (b=1; b<=9; b++){
            printf("%d * %d = %2d   ", a, b, a*b);
        }
        putchar('\n');
    }

    puts("\n以列排的乘法表");

    for (a=1; a<=9; a++){
        for (b=1; b<=a; b++){
            printf("%d * %d = %2d   ", a, b, a*b);
        }
        putchar('\n');
    }

    puts("\n以列排颠倒");

    for (a=1; a<=9; a++){
        // 打出占位的, 可以使用全空格
        for (b=1; b<=9-a; b++){
            printf("0 * 0 = %2d   ", 0);
        }

        for (b=1; b<=a; b++){
            printf("%d * %d = %2d   ", a, b, a*b);
        }
        putchar('\n');
    }


    return 0;
}