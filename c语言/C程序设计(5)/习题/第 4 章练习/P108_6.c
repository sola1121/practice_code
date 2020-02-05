#include "stdio.h"

int main(){
    float x, y;
    char *output = "y's value: %f\n";
    printf("input x's value: ");
    scanf("%f", &x);

    if (x<1){
        printf(output, x);
    } else if (x>=1 && x<10){
        printf(output, 2 * x -1);
    } else if (x>=10){
        printf(output, 3 * x -11);
    } else {
        printf("something wrong with the number.\n");
    }
    return 0;
}
