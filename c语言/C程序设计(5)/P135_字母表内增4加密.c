#include "stdio.h"

/*
  单词表循环式的, 比如超过Z, 那么重新从A开始计数余下的几位
  卡过的地方: 关系运算符不能连着写, 如 97<=ch<=122, 其从左到右计算,
            如果ch为大于97的值, 会变成1<=122, 而不能判断ch是否小于122
  c的函数传递是值传递, 需要引用传递得写(int *ch)传入指针. 使用%p查看指针地址
*/

unsigned int move_encryption(unsigned int ch){   // c参数传递使用值传递
    int step = 4;
    if ((97<=ch && ch<=122) || (65<=ch && ch<=90)){   // a 97, z 122;  A 65, Z 90   , 相差25
        ch += step;
        if (ch>'z' && ch<=126)
            ch = 'a' + ch - 'z' - 1;
        else if (ch>'A' && ch<=94)
            ch = 'A' + ch - 'Z' - 1;
        return ch;
    } else {
        return 0;
    }
}


int main(){
    char c, convert_c;                                                                                                                                                                                                                                                                                                                              
    printf("输入字符串: ");
    while((c=getchar())!='\n'){   // 注意这里的执行顺序, 关系运算符优先级高于赋值
        convert_c = move_encryption(c);
        if (convert_c){
            printf("%c", convert_c);
        } else {
            printf("%c", c);
        }
        
    }

    printf("\n");   // printf接受格式字符串
    return 0;
}
