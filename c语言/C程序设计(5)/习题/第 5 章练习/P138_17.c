#include "stdio.h"
#include "string.h"

/*
    两队比赛, 甲 A B C, 乙 X Y Z. A不和X, C不和X,Z, 找出三队比赛名单
*/

int main(){
    char list_1[3] = {'A', 'B', 'C'};
    char list_2[3] = {'X', 'Y', 'Z'};

    for (int row=0; row<sizeof(list_1); row++){
        for (int line=0; line<sizeof(list_2); line++){
            if (list_1[row] == 'A' && list_2[line] == 'X') continue;
            if (list_1[row] == 'C' && list_2[line] == 'X') continue;
            if (list_1[row] == 'C' && list_2[line] == 'Z') continue;
            printf("%c - %c\n", list_1[row], list_2[line]);
        }
    }

    return 0;
}