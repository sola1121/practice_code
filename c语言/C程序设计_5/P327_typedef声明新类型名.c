/*
    typedef用来替代原有或一些复杂的类型表示方式

    typedef int Integer;   // 使用Integer代表原int

    typedef struct {
        int month;
        int day;
        int year;
    } Date;   // 使用Date代表一个结构体
    Date birthday;
    Date *pt;

    typedef int Num[100];   // 声明Num为整形数组类型名
    Num a;   // 定义a为整型数组名, 它有100个元素

    typedef char * String;   // 使用String为代表一个字符指针
    String pt, str[10];   // pt为字符指针变量, str为字符指针数组

    type int (*func_pt)();   // 声明func_pt为指向函数的指针类型, 该函数返回int
    func_pt pt1, pt2;   // pt1, pt2为func_pt类型的指针变量

    如何定义:
        按定义变量的方式, 把变量名换上新类型名, 并且在最前面加typedef, 就声明了新类型名代表原来的类型.
*/