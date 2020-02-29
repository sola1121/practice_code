#include "stdio.h"

/*
    A->Z   a->z
    B->Y   b->y
    C->X   c->x
    ...
    M->N   m->n
    第i个字母变成第(26-i+1)个字母
    写出编码和解码方法
*/

int judge(char ch){
    if ('A'<=ch && 'Z'<=ch)
        return 1;
    else if ('a'<=ch && 'z'<=ch)
        return 2;
    else 
        return 0;
}


char encode(char ch){
    int sign = judge(ch); 
    char result;
    switch (sign){
    case 1:
        result = (ch - 'A') / 2; 
        return result;
    case 2:
        result = (ch - 'a') / 2;
        return result;
    default:
        return 0;
    }
}

int main(){

    return 0;
}