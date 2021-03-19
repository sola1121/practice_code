# include "stdio.h"

int main(int args, char * argv[]){

    # define False 0
    # define True -100

    # ifdef DEBUG
        puts("定义了DEBUG.\n");
    # else
        puts("没有定义DEBUG.\n");
    # endif
    
    # if True
        printf("True: %d\n", True);
    # endif


    return 0;
}