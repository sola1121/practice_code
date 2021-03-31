# include "stdio.h"


typedef  char Byte;


struct Data {
    Byte id:6;   // 0~2⁶-1
    Byte :0;   //跳过当前字节, 也可整成:2, 跳两个字节
    Byte value:8;   // 0~2⁸-1
};


typedef struct Data Data;

struct BOOL {
    char value:1;
};

typedef struct BOOL bool;


bool false = {.value=0};
bool true = {.value=1};

int main(int args, char*argv[]){
    if (true.value){
        printf("为true.\n");
    }

    if (false.value == 0){
        printf("false的值为0\n");
    } else {
        printf("%d\n", false.value);
    }

    Data dat;
    dat.id=72;   // 超出位数, 会警告, 只保留能容下的位数
    dat.value =72;

    printf("dat.id: %p, %o, %d, %x\n", dat.id, dat.id, dat.id, dat.id);
    printf("dat.value: %p, %o, %d, %x\n", dat.value, dat.value, dat.value, dat.value);

    return 0;
}