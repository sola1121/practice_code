#include "stdio.h"

int main(){
    float grade;
    char *format = "You grade level is %c\n";
    printf("enter your grade: ");
    scanf("%f", &grade);

    if (grade>=90 && grade<=100){
        printf(format, 'A');
    } else if (grade>=80 && grade<90){
        printf(format, 'B');
    } else if (grade>=70 && grade<80){
        printf(format, 'C');
    } else if (grade>=60 && grade<70){
        printf(format, 'D');
    } else if (grade>=0 && grade<60) {
        printf(format, 'E');
    } else {
        printf("eat shit.\n");
    }

    return 0;
}
