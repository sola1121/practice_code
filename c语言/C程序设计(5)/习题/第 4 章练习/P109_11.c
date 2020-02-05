#include "stdio.h"

void main(){
    float f[4], temp;
    printf("输入四个数, 有小到大排列: ");
    scanf("%f%f%f%f", &f[0], &f[1], &f[2], &f[3]);

    for (int j=0; j<4; j++){
        for (int k=0; k<4; k++){
            if (f[j]<f[k]){
                temp = f[j];
                f[j]=f[k];
                f[k] = temp;
            }
        }
    }

    for (int i=0; i<4; i++){
        printf("%f  ", f[i]);
    }
    printf(" \n %d \n", sizeof(f));
}
