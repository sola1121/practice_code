#include "stdio.h"


void main(){
    char *ch = "* * * * *";

    for (int line=0; line<5; line++){
        for (int space=5-line; space<5; space++){
            printf("%c", ' ');
        }
        printf("%s\n", ch);
    }

}