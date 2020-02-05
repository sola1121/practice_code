#include "stdio.h"
#include "math.h"

#define Pi 3.1415926

/*
  求圆的周长,面积,球体表面积,球体体积,圆柱体积
   C=πd    S=πr**2   S=πD**2  V＝4πR³ /3   V = hπr**2

*/

int main(){
    float r = 1.5, h = 3.0;
    float C, S, S1, V, V1;

    C = Pi * 2 * r;   // 圆周长
    S = Pi * pow(r, 2);  // 圆面积
    S1 = Pi * 4 * pow(r, 2);   // 球体表面积
    V = Pi * 4 * r * r *r / 3;
    V1 = Pi * h * pow(r, 2);

    printf("圆的周长: %.2f, 圆的面积: %.2f \n球体表面积: %.2f, 球体体积: %.2f \n圆柱体积: %.2f",
           round(C*100)/100, round(S*100)/100, round(S1*100)/100, round(V*100)/100, round(V1*100)/100);

    getchar();
    return 0;
}
