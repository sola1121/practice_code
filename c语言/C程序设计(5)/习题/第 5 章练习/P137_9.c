#include "stdio.h"

#define limit 1000
#define factor_length 100

/*
  1000 内完数, 1*2*3 == 6, 6 == 1 +2 +3
*/

void set_factor_array_0(int *arr){   // 数组本生就是引用传递
    for (int c=0; c<factor_length; c++)
        arr[c] = 0;
}

int main(){
    int sum, count, factors[factor_length]={0};

    for (int num=2; num<=limit; num++){
        set_factor_array_0(factors);
        sum = 0, count = 0; 
        for (int i=1; i<=num/2; i++){
            if (num % i == 0){
                factors[count] = i;   // 在array中记录因数
                count += 1;
                sum += i;
            }
        }
        if (num == sum){
            printf("%d its factors are ", num);
            for (int c=0; c<factor_length; c++){
                if (factors[c]!=0) printf("%d, ", factors[c]);
            }
            printf("\n");
        }
    }

    printf("\n");
    return 0;
}