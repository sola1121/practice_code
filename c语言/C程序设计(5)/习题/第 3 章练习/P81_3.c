#include "stdio.h"
#include "math.h"

/*
  ���������д���d, ÿ�»����p, ������r, ��m�º���
  m = (log(p) - log(p-d*r))/log(1+r) ��д�� m = log(p/p-d*r)/log(1+r)
*/

int main(){
    float d = 300000.0, p = 6000.0, r = 0.01, m;
    m = (log10(p) - log10(p-d*r))/log10(1+r);
    printf("����Ҫ %.1f ���²��ܻ���.\n", round(m*10)/10);
    getchar();
    return 0;
}
