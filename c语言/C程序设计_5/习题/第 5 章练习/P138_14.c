#include "stdio.h"
#include "math.h"

/*
    牛顿迭代法求 2x**3 - 4x**2 + 3x - 6 = 0 在1.5附近的根
*/

int main(){
    double x, y, epsilon = 10e-4;
    for (x=1; x<=4; x+=10e-5){
        y = 2 * pow(x, 3) - 4 * pow(x, 2) + 3 * x - 6;
        if (fabs(y)<epsilon) {
            printf("求得的x近似值 %lf\n", x);
            break;
        }
    }

    return 0;
}