#include"stdio.h"

int main(){
    double a, b, c, temp;
    char *format_str = "最大为: %lf";
    scanf("%lf%lf%lf", &a, &b, &c);
    if(a>b){
        temp = a;
    } else {
        temp = b;
    }
    if (c>temp){
        temp = c;
    } else {
        printf(format_str, c);
        return 0;
    }
    printf(format_str, temp);
    return 0;
}
