#include <stdio.h>

int main(){
    int row = 0;
    while (row<4){
        for (int count=0; count<row; count++){
            printf("%s", " ");
        }
        printf("%s", "*****\n");
        row ++;
    }
    return 0;
}

/*
打印结果
*****
 *****
  *****
   *****

*/