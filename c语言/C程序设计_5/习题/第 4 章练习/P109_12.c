#include "stdio.h"
#include "math.h"

int main(){
    int flag = 0;
    double point[4][2] = {{2, 2}, {-2, 2}, {-2, -2}, {2, -2}}, x, y, distance;
    printf("输入一个坐标: ");
    scanf("%lf, %lf", &x, &y);

    for(int i=0; i<4; i++){
        distance = fabs( sqrt( pow(point[i][0]-x, 2) + pow(point[i][1]-y, 2) ) );
        if (distance<=1){
            flag = 1;
            break;
        }
    }

    switch (flag){
    case 0:
        printf("此处高度为0.\n");
        break;
    case 1:
        printf("此处高度为10m, 位于高塔坐标.\n");
    }

    return 0;
}