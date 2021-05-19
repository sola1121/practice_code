# include "stdio.h"


int main(int args, char * argv){
    int a = 1, b = 1;

    puts("\n列排, ▇ 形, 全部打印");
    // a in range(1, 10)
    // 内循环 b in range(1, 10)
    for (a=1; a<=9; a++){
        for (b=1; b<=9; b++){
            printf("%d * %d = %2d   ", a, b, a*b);
        }
        putchar('\n');
    }

    puts("\n列排, ◣ 形乘法表(标准)");
    // a in range(1, 10)
    // 内循环 b in range(1, a)
    // b 每次在a的循环内的时候从1开始, 循环到b<=a, 这样每行只打印到当前a的值, 而a的值从1开始, 形成每行打印的次数增加
    for (a=1; a<=9; a++){
        for (b=1; b<=a; b++){
            printf("%d * %d = %2d   ", a, b, a*b);
        }
        putchar('\n');
    }

    puts("\n行排, ◤ 形乘法表");
    // a in range(1, 10)
    // 内循环 b in in range(a, 9)
    // b 每次在a的循环内的时候从a的值开始, 循环到b<=9, 这样就是每行打印到最后的9, 而a的值每次都会减少, 形成每行打印的次数减少
    for (a=1; a<=9; a++){
        for (b=a; b<=9; b++){
            printf("%d * %d = %2d   ", a, b, a*b);
        }
        putchar('\n');
    }

    puts("\n列排, ◥ 形乘法表");
    // a in range(1, 10)
    // 内循环 b in range(1, 10)
    // b 每次在a的循环内的时候从1开始, 循环到b<=9, 这样每行打印到最后的9, 每行都打印一样的次数
    // 但是当 b<a的时候, 不打印内容
    for (a=1; a<=9; a++){
        for (b=1; b<=9; b++){
            // 打印占位的, 可以全部使用空格
            if (b<a)
                printf("0 * 0 = %2d   ", 0);
            else 
                printf("%d * %d = %2d   ", a, b, a*b);
        }
        putchar('\n');
    }

    puts("\n行排, ◢ 形乘法表");
    // a in range(1, 10)
    // 内循环 b in range(1, 9-a)
    // 内循环 b in range(1, a)
    // b 每次在a的循环内的时候从1开始, 循环到b<=9-a, a的值使递增的, 这样每行打印的内容会变少, 以此来打印占位
    // b 每次在a的循环内的时候从1开始, 循环到b<=a, 这样每行只打印到当前a的值, 而a的值从1开始, 形成每行打印的次数增加
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