#include "stdio.h"
#include "math.h"

/*
  购房从银行贷了d, 每月还款额p, 月利率r, 求m月后还清
  m = (log(p) - log(p-d*r))/log(1+r) 或写作 m = log(p/p-d*r)/log(1+r)
*/

int main(){
    float d = 300000.0, p = 6000.0, r = 0.01, m;
    m = (log10(p) - log10(p-d*r))/log10(1+r);
    printf("将需要 %.1f 个月才能还清.\n", round(m*10)/10);
    getchar();
    return 0;
}
