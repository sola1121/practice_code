/*
    如果一个变量只有几种可能的值, 则可以定义为枚举(enumeration)类型.
    枚举是指把可能的值一一列举出来, 变量的值只限于列举出来的值的范围内.

    声明枚举类型使用enum开头, 如: enum Weekday{mon, tue, wed, thu, fri, sat, sun};
    枚举变量和其他数值型量不同, 它们的值只限于花括号中指定的值之一.

    使用方式
        enum 枚举名 {枚举元素列表};
        enum 枚举名 枚举变量;

        // 不声明有名字的枚举类型
        enum {枚举元素列表} 枚举变量;

    注意
        C编译对枚举类型的枚举元素按照常量处理, 故称枚举常量. 不要因为它们是标识符(有名字)而把它们看做变量, 不能对它们赋值.

        每一个枚举元素都代表一个整数, C语言编译按定义时的顺序默认它们的值为0, 1, 2, ....
            若有赋值语句 workday = mon; 相当于 workday = 0;
        枚举常量是可以引用和输出的. 如: printf("%d\n", workday);

        枚举元素的数值可以在声明枚举类型的时候显式的人工指定.
            enum Weekday {mon=1, tue, wed, thu, fri, sat, sun};
        上面mon变为了1, 后面的tue, wed等, 在此基础上依然默认多1, 变为2, 3等

        由于枚举型变量的值是整数, 因此C99把枚举类型也作为整形数据中的一种, 即用户自定义的整数类型.
*/

# include "stdio.h"

// 口袋中有红, 黄, 蓝, 白, 黑5种颜色的求若干个. 每次从口袋中先后取出3个球, 
// 问得到三种过过过过不同颜色的球的可能取法, 输出每种排列的情况.
// 5个里面拿一个, 4个里面拿一个, 3个里面拿一个, 总5*4*3=60


int main(){
    enum Color {red, yellow, blue, white, black};
    enum Color first, second, third, privious;
    
    int count, loop;
    
    count = 0;
    for (first=red; first<=black; first++){   // 第一次抽取
        for (second=red; second<=black; second++){   // 第二次抽取
            if (first != second){
                for (third=red; third<=black; third++){   // 第一次抽取与第二次抽取的颜色不一样, 进行第三次抽取
                    if ((third!=first) && (third!=second)){
                        count = count+1;
                        printf("%-4d", count);
                        for (loop=1; loop<=3; loop++){   // 符合条件将这三个球色进行输出
                            switch(loop){
                                case 1: privious = first; break;
                                case 2: privious = second; break;
                                case 3: privious = third; break;
                                default: break;
                            }
                            switch(privious){
                                case red: printf("%-10s", "red"); break;
                                case yellow: printf("%-10s", "yellow"); break;
                                case blue: printf("%-10s", "blue"); break;
                                case white: printf("%-10s", "white"); break;
                                case black: printf("%-10s", "black"); break;
                                default: break;
                            }
                        }
                        printf("\n");
                    }
                }
            }
        }
    }

    printf("\ntotal: %5d\n", count);

    return 0;
}