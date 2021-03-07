#include "stdio.h"
#define SUM 100000


void main(){
    float amount, aver, total;
    int i;
    
    // 程序最多执行1000次, 当total值达到SUM, 将会使用break退出循环执行进而执行循环之后的语句
    for (i=1, total=0; i<=1000; i++){   // 在for中初始化了i和total, 如果没有, 其值将会不确定
        printf("输入金额: ");
        scanf("%f", &amount);
        total += amount;
        if (total >= SUM) break;
    }
    printf("共%f, 计数%d, 平均%.2f\n", total, i, total/i);

    // 输出100~200之间不能被3整除的数, 当能整除的时候, 应该提前结束本次循环, 接着执行下一次循环, 这里使用continue
    int n;
    for (n=100; n<=200; n++){   // 这里初始化n
        if (n % 3 == 0)
            continue;
        printf("%d ", n);
    }
}