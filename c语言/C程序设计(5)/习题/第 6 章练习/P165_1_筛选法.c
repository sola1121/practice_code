#include "stdio.h"

#define limit 100

/*
    使用筛选法找出100之内的素数
*/

int main(){
    int number = 2, factor = 2, BOOL = 1;

    while (number<limit){
        BOOL = 1;
        for (factor = 2; factor<number/2; factor++){
            if (number % factor == 0){
                BOOL = 0;
            }
        }
        if (BOOL)
            printf("%4d", number);
        number += 1;
    }
    

    printf("\n");
    return 0;
}