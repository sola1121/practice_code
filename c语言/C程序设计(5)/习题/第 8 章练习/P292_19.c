# include "stdio.h"
# include "stdlib.h"


void * new(unsigned long n){
    return (char *) malloc(n);
}


void free2(char * pt){
    free(pt);
}


int main(){
    char * s = NULL;
    s = new(64);
    printf("分配的地址: %p\n", s);
    free2(s);

    return 0;
}