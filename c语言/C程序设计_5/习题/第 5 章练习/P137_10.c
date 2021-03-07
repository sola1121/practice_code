#include "stdio.h"

/*
  1, 1, 2, 3, 5, 8, 13, 21,...
  斐波那契数列 2/1 + 3/2 + 5/3 +...
*/

unsigned long fab(int n){
    // 输入项数, 返回对应的数列值 
    unsigned int a1 = 1, a2 = 1, a3 = 2;
    while (n>2){
        a2 = a3;
        a3 = a1 + a2;
        a1 = a2;
        --n;
    }
    return a1;
}


int main(){
    double sum = 0.0;
    for (int i=1; i<=20; i++){
        printf("%ld/%ld", fab(i+2), fab(i+1));
        if (i != 20) printf(" + ");
        sum += (double)fab(i+2) / (double)fab(i+1);
    }

    printf(" = %lf\n", sum);
    return 0;
}