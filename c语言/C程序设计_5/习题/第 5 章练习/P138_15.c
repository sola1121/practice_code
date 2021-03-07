#include "stdio.h"
#include "math.h"

/*
    二分法法求 2x**3 - 4x**2 + 3x - 6 = 0 在(-10, 10)附近的根
*/

int main(){
    double x, y, low, high, epsilon = 10e-4;
    low = -10, high = 10;

    do {
        x = (low + high) / 2;
        y = 2 * pow(x, 3) - 4 * pow(x, 2) + 3 * x - 6;
        if (y < 0){
            low = x;
        } else if (y > 0){
            high = x;
        }
    } while (fabs(y)>=epsilon);

    printf("求得x的近似值: %lf\n", x);
    return 0;
}