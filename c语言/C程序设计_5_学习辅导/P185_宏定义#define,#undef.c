# include "stdio.h"

# define MAX(x, y) x>y?x:y

# define Print printf
# define Integer "大值: %d"
# define Endln "\n"
# define OUT Integer Endln


int main(int args, char * argv[]){
    int num1 = 2, num2 = 3;
    
    printf("大值: %d\n", MAX(num1, num2));

    printf("%s\n", OUT);

    Print(OUT, MAX(num1, num2));

// # undef Endln

//     printf("%s\n", OUT);

// 因为Endln是OUT的组成部分, 所以当释放Endln的时候, OUT也没法用了

    return 0;
}
