#include "stdio.h"

typedef int bool;
#define True 1
#define False 0

#define and &&
#define or ||
#define not !

int main(){
    bool t = True, f = False;

    printf("True: %d, False: %d \n", True, False);

    if (True) printf("是的,自定义的True可以用.\n");
    if (!False) printf("是的,自定义的False可以用.\n");

    if (t and t) printf("True and True 成功执行.\n");
    if (t or f) printf("True or False 成功执行.\n");
    if (not f) printf("not False 成功执行.\n");

    //优先级: 逻辑非(!) > 关系运算符 > 算数运算符 > 逻辑与(&&) 逻辑或(||) > 赋值运算符
    printf("%d\n", 4&&4-!4);
    return 0;
}
