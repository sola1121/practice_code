# 动态内存分配与指向它的指针变量

<!-- TOC -->

- [动态内存分配与指向它的指针变量](#动态内存分配与指向它的指针变量)
    - [什么是内存的动态分配](#什么是内存的动态分配)
    - [怎样建立内存的动态分配](#怎样建立内存的动态分配)
        - [malloc函数开辟动态存储区](#malloc函数开辟动态存储区)
        - [calloc函数开辟动态存储区](#calloc函数开辟动态存储区)
        - [realloc函数重新分配动态存储区](#realloc函数重新分配动态存储区)
        - [free函数释放动态存储区](#free函数释放动态存储区)
        - [sizeof() 运算符](#sizeof-运算符)
            - [运算表现](#运算表现)
            - [应用场景](#应用场景)
    - [void指针类型](#void指针类型)
    - [示例](#示例)

<!-- /TOC -->

## 什么是内存的动态分配

全局变量是分配在内存中的静态存储区的, 非静态的局部变量(包括形参)是分配在内存中的动态存储区的, 这个存储区是一个称为**栈(stack)**的区域. 除此之外, C语言还允许建立内存动态分配区域, 以存放一些临时用的数据, 这些数据不必在程序的声明部分定义, 也不必等到函数结束时才释放, 而是需要时开辟, 不需要时释放. 这些数据是临时存放在一个特别的自由存储区, 称为**堆(heap)**. 可以根据需要, 向系统申请所需大小的空间. 由于未在声明部分定义它们为变量或数组, 因此不能通过变量名或数组名去引用这些数据, 只能通过指针来引用.

## 怎样建立内存的动态分配

alloc (allocate) : 分配

对内存的动态分配是通过系统提供的库函数来实现的, 主要有malloc, calloc, free, realloc这是四个函数.

以上这些函数都在 stdlib.h 库中. # include "stdlib.h"进行使用

### malloc函数开辟动态存储区

void * malloc(unsigneed int size);

其作用是在内存的动态存储区中分配一个长度为size的连续空间. 形参size的类型定位无符号整型. 此函数的值(即"返回值")是所分配区域的第一个字节的地址, 或者说, 此函数是一个指针型函数, 返回的指针指向该分配域的第一个字节.

    malloc(100)   // 开辟100字节的临时分配域, 函数值为其第一个字节的地址

注意指针的基类型为void, 即不指向任何类型的数据, 只提供一个纯地址. 如果此函数未能成功地执行(例如内存空间不足), 则返回空指针(NULL).

### calloc函数开辟动态存储区

void * calloc(unsigned n, unsigned size);

其作用是在内存的动态存储区中分配n个长度为size的连续空间, 这个控件一般比较大, 足以保存一个数组.

用calloc函数可以为一维数组开辟动态存储空间, n为数组元素个数, 每个元素长度为size. 这就是动态数组. 函数返回指向所分配域的第一个字节的指针; 如果分配不成功, 返回NULL.

    p = calloc(50, 4);   // 开辟50×4个字节的临时分配域, 把首地址赋给指针变量

### realloc函数重新分配动态存储区

void * realloc(void *p, unsigned int size);

如果已经通过malloc函数或calloc函数获得了动态空间, 想改变其大小, 可以用realloc函数重新分配.

用realloc函数将p所指向的动态空间的大小改变为size. p的值不变. 如果重分配不成功, 返回NULL.

    realloc(p, 60);   // 将p指向的已分配的动态空间改为60字节

### free函数释放动态存储区

void free(void *p);

其作用是释放指针变量p所指向的动态空间, 使这部分空间能重新被其他变量使用. p应是最近一次调用malloc或calloc函数时得到的函数返回值.

    free(p);   // 释放指针变量p所指向的已分配的动态空间

### sizeof() 运算符

sizeof是C语言的一种单目操作符, 如C语言的其他操作符++、--等. 它并不是函数. sizeof操作符以字节形式给出了其操作数的存储大小. 操作数可以是一个表达式或括在括号内的类型名.操作数的存储大小由操作数的类型决定.

    int a = 1;
    sizeof(a);
    sizeof a;
    sizeof(int)

注意: sizeof操作符不能用于函数类型, 不完全类型或位字段。不完全类型指具有未知存储大小的数据类型, 如未知存储大小的数组类型、未知内容的结构或联合类型、void类型等。

sizeof操作符的结果类型是size_t，它在头文件\<stddef.h>中typedef为unsigned int类型。该类型保证能容纳实现所建立的最大对象的字节大小。

sizeof的优先级为2级，比/、%等3级运算符优先级高。它可以与其他操作符一起组成表达式。如i*sizeof(int)；其中i为int类型变量。

#### 运算表现

当操作数具有数组类型时，其结果是数组的总字节数。但如果是作为void func(int *arr)函数中的数组, 这时这个数组其实是一个指针, 这个指针记录了该数组的地址, 如果使用sizeof, 则返回系统指针的大小, 4或者8

联合类型操作数的sizeof是其最大字节成员的字节数。

结构类型操作数的sizeof是这种类型对象的总字节数，包括任何垫补在内。

让我们看如下结构：

　　struct {char b; double x;} a;

在某些机器上sizeof(a)=12，而一般sizeof(char)+ sizeof(double)=9。这是因为编译器在考虑对齐问题时，在结构中插入空位以控制各成员对象的地址对齐。如double类型的结构成员x要放在被4整除的地址。

如果操作数是函数中的数组形参或函数类型的形参，sizeof给出其指针的大小

#### 应用场景

sizeof操作符的一个主要用途是与存储分配和I/O系统那样的例程进行通信

　　void *malloc(size_t size)

　　size_t fread(void * ptr,size_t size,size_t nmemb,FILE * stream)

sizeof的另一个的主要用途是计算数组中元素的个数。

    void * memset(void * s,int c,sizeof(s))

由于操作数的字节数在实现时可能出现变化，建议在涉及到操作数字节大小时用ziseof来代替常量计算。

## void指针类型

基类型为void的指针类型, 即void*型变量, 它不指向任何类型的数据. 在将它的值赋给另一个指针变量的时候, 由系统对它进行类型转换, 使之适合于被复制的变量类型.

    int a = 3;
    int * p1 = &a;
    char * p2;
    void * p3;   // p3为void指针变量
    p3 = (void *) p1;   // 将p1的值转换为void*型, 然后赋值给p3
    p2 = (char *) p3;   // 将p3的值转换为char*型, 然后赋值给p2
    printf("%d", *p1);  // 合法, 输出整形变量a的值
    p3 = &a; printf("%d", *p3);   // 错误, p3是无指向的, 不能指向a

地址应包含基类型的信息, 即存放在以此地址标志对的存储单元中的数据的类型, 否则无法实现对数据的存取. 那么这种void*无指向的地址所标志的存储单元中是不能存储任何数据的, 也就是说, 无法通过这种地址对内存存取数据.

在调用动态存储分配函数(如: malloc, caloc, realloc)时出现. 这些函数开辟动态存储区, 用户是希望获得此动态存储区的起始地址, 以便利用该动态存储区. 这种指针不指向任何类型的数据. 不能企图通过它存取数据, 这程序中它只是过度性的, 只有转换为有指向的地址, 才能存取数据.

在C99以前, 动态内存分配是返回的char*, 但因为开辟动态存储区域不是一定用来存放字符型数据的, 所以, 才有了使用void*指针代表无指向的地址. 其准许你C语言中对指针的有关规定, 它也有基类型, 只是是void无类型.

    void * p;   // 直接定义void*型的指针变量

现在所用的一些编译系统在进行地址赋值时, 会自动进行类型转换

    int * pt;
    pt = (int *) malloc(100);   // malloc(100)是void*型, 把它转换为int*型

也可以简化为

    int * pt;
    pt = malloc(100);   // 自动类型转换

示例:

    int * p_arr;
    p_arr = (int *) malloc(5*sizeof(int));   // 也可 p_arr = mallocc(5*sizeof(int));

程序中没有定义数组, 而是开辟一段动态自由分配区, 作为动态数组使用. 这样p_arr就指向了一个连续的地址头. 可以用p_arr+i来遍历这个地址段, 并可以向其中存取值.

void array[] 作为函数参数是不行的

## 示例

函数返回自身创建的数组指针

    # include "stdio.h"
    # include "malloc.h"
    # include "string.h"


    struct Data {
        int num;
        char content[1024];
    };


    typedef struct Data Data;


    Data * create_data(){
        Data *d = NULL;
        d = (Data *)calloc(2, sizeof(Data));   // 开辟2块struct Data大小的内存, 表现形式位数组

        // 赋值
        (d+0)->num = 0;
        strcpy((d+0)->content, "内容1.");   // d[0].num, d[0].content 也是可以的
        (d+1)->num = 1;
        strcpy((d+1)->content, "内容2.");   // d[1].num, d[1].content 也是可以的

        return d;
    }


    int main(){
        Data * d = NULL;

        d = create_data();

        puts("指针样式访问内存块");
        printf("d+0 %d, %s\n", d->num, d->content);
        printf("d+1 %d, %s\n", (d+1)->num, (d+1)->content);

        puts("数组样式访问内存块");
        printf("d[0] %d, %s\n", d[0].num, d[0].content);
        printf("d[1] %d, %s\n", d[1].num, d[1].content);

        free(d);

        return 0;
    }
