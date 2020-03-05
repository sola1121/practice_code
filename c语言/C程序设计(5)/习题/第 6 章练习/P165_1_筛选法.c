#include "stdio.h"

#define limit 100

/*
    使用筛选法找出100之内的素数
    列出所有的数, 然后逐个判断它们是否是素数.
    步骤:
        1. 去掉1
        2. 用2除它后面的各个数, 去掉能被整除的.
        3. 用3除它后面的各个数, 去掉能被整除的.
        ...
        到除数为sqrt(原数)时, 就可以停止了.
*/

int main(){
    int number = 2, factor = 2, BOOL = 1;

    while (number<limit){
        BOOL = 1;   // 重置, 默认该数是一个素数
        for (factor = 2; factor<=number/2; factor++){
            if (number % factor == 0){
                BOOL = 0;
                break;
            }
        }
        if (BOOL)
            printf("%4d", number);
        number += 1;
    }
    

    printf("\n");
    return 0;
}