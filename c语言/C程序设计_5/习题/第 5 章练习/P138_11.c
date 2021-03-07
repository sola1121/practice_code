#include "stdio.h"

#define total 100.0
#define time 10

/*
  弹球, 着地反弹一半高度, 经过n次落地总共弹跳多少
*/

int main(){
    int count = 0;
    double sum = total, temp = total; 
    while (count<time){
        temp = temp/2;
        sum += temp;
        count ++;
        if (count==9) printf("第%d跳了%.4lfm\n", count+1, temp);
    }
    
    printf("球一共移动了: %.4lfm\n", sum);

    return 0;
}