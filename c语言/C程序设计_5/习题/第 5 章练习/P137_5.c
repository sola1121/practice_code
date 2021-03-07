#include "stdio.h"
#include "math.h"

/*
    a + aa + aaa + aaaa + ... 
*/

const unsigned int a=1;

int main(){
    printf("计数下标n: ");
    unsigned int n;
    unsigned long temp, result = 0;
    scanf("%d", &n);
    
    for (unsigned int count=1; count<=n; count++){
        temp = 0;   // 重置
        for (unsigned int v=0; v<count; v++){
            temp += a * pow(10, v);
        }
        printf("%ld", temp);
        if (count != n) printf("+");
        result += temp;
    }

    printf(" = %ld\n", result);

    return 0;
}