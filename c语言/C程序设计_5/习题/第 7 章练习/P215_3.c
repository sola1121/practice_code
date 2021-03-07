#include "stdio.h"

int judge_prime(int num){
    for (int factor=2; factor<num/2; factor++)
        if (num%factor==0)
            return 0;
    return 1;
}


void main(){
    int input_num;

    printf("输入一个整数(0退出): ");
    while (scanf("%d", &input_num)){
        if (input_num==0)
            return 0;
        
        switch (judge_prime(input_num)){
        case 1:
            printf("%d 是素数.\n", input_num);
            break;
        case 0:
            printf("%d 不是素数.\n", input_num);
            break;
        default:
            printf("¿¿¿¿¿¿¿\n");
        }
    }

}