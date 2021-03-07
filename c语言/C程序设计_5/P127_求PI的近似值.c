#include "stdio.h"
#include "math.h"

// π/4≈1-1/3+1/5-1/7+...

int main(){
    int  count = 0;
    double n = 1.0, sum = 0.0;
    while (1) {
        if (count % 2 == 0){
            sum += 1/n;
        } else {
            sum -= 1/n;
        }
        if (fabs(1/n) < 1e-6){
            break;
        }
        count += 1;
        n += 2;
    }

    printf("π/4≈%lf, so π≈%lf\n", sum, sum*4);

    return 0;
}         