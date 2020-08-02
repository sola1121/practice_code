# include "stdio.h"

/*
1. 定义指向函数的指针变量, 并不意味着这个指针变量可以指向任何函数, 它只能指向在定义时指定的类型的函数.
   在一个程序中, 一个指针变量可以先后指向同类型的不同函数.

2. 如果要用指针调用函数, 必须向使指针指向该函数
    如: pt = func;  不能pt = func(a, b), 这样就是调用函数func并将返回值赋给pt

3. 在给函数指针变量赋值时, 只需给出函数名而不必给出参数

4. 用函数指针变量调用函数时, 只需将(*pt)代替函数名即可(pt为指针变量名), 在(*pt)之后的括号中根据需要写上实参.
    (*pt)(a, b); 如果函数有返回值, c = (*pt)(a, b);

5. 对指向函数的指针变量不能进行算术运算

6. 用函数名调用函数, 只能调用所指定的一个函数, 而通过指针变量调用函数比较灵活, 可以根据不同情况先后调用不同的函数.

*/

int max(int x, int y){
    return x>y?x:y;
}

int min(int x, int y){
    return x>y?y:x;
}


int main(){
    int a, b, c;
    int (*func_p)(int, int);   // 用于指向函数的指针
    func_p = max;   // 让指针指向函数

    printf("Enter a and b: ");
    scanf("%d, %d", &a, &b);
    c = (*func_p)(a, b);   // 通过指针调用函数
    printf("a=%d, b=%d, c=%d\n", a, b, c);


    /* 函数指针应用, 根据用户选择, 指向不同的函数并调用 */
    start_select:
    printf("\n1. 选择max\n2. 选择min\n: ");
    scanf("%d", &c);

    switch (c){
    case 1:
        func_p = max;
        break;
    case 2:
        func_p = min;
        break;
    default:
        printf("请输入1或2来选择");
        goto start_select;
        break;
    }

    printf("求 %s, 值 %d\n", c==1?"max":"min", (*func_p)(a, b));

    return 0;
}