#include "stdio.h"

/*
    一车面包人, 问第n号人年龄, 其说其是n-1号人年龄+2, 最后问到1号, 他说他10岁

    record 1: 10
    record 2: 12
    record 3: 14
    record 4: 16
    record 5: 18
    NO.5 age: 18

    递推 record(1) 10 -> record(2) 12 -> record(3) 14 -> record(4) 16 -> record(5) 18
         <-             <-               <-              <-             <-   回溯
*/

int age(int);

int main(){
    printf("NO.5 age: %d\n", age(5));
    return 0;
}

int age(int n){
    int record;
    if (n==1){   // 使用if来判断结束
        record = 10;
    } else {
        record = age(n-1) + 2;   // 进行自身的调用
    }
    printf("record %d: %d\n", n, record);
    return record;
}