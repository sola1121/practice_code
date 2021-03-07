#include "stdio.h"
#include "math.h"

/*
    解一元二次函数
*/

void delta_gt_0(float a, float b, float c){
    float result[2] = {0};
    result[0] = (-b + sqrtf(b*b - 4*a*c)) / 2*a;
    result[1] = (-b - sqrtf(b*b - 4*a*c)) / 2*a;
    printf("delta>0, 解: %f, %f\n", result[0], result[1]);
}

void delta_eq_0(float a, float b, float c){
    float result = 0;
    result = (-b - sqrtf(b*b - 4*a*c)) / 2*a;
    printf("delta==0, 解: %f\n", result);
}


int main(){
    float a, b, c, delta = 0, *result;

    printf("输入a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);
    if (a==0){
        printf("a==0\n");
        return 0;
    }

    delta = b*b - 4*a*c;
    if (delta<0){
        printf("delta=%f, 函数无解.\n", delta);
    } else if (delta==0){
        printf("delta=%f, ", delta);
        delta_eq_0(a, b, c);
    } else if (delta>0){
        printf("delta=%f, ", delta);
        delta_gt_0(a, b, c);
    } else {
        printf("¿¿¿¿¿¿¿\n");
    }

    return 0;
}