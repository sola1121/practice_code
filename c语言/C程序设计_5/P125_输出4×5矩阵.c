#include "stdio.h"

int main(){
    // 1
    for (int i=1; i<=20; i++){
        printf("%3d", i);
        if (i % 5 == 0) printf("\n");
    }

    printf("\n===================\n");

    // 2
    for (int j=1; j<=4; j++){
        for (int k=0, temp=j; k<5; k++){
            printf("%3d", temp);
            temp+=j;
        }
        printf("\n");
    }
    // 来看看在for循环中定义的变量是不存在于循环周期外
    return 0;
}