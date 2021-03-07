#include "stdio.h"
#include "string.h"

#define len 80

void reverse_string(char* string){
    char temp;
    size_t length = strlen(string);
    for (int i=0; i<length/2; i++){
        temp = string[i];
        string[i] = string[length-i-1];
        string[length-i] = temp;
    }
}


void main(){
    char input[len] = "12345";
    // fgets(input, len, stdin);
    printf("当前: %s\n", input);

    reverse_string(input);
    printf("转置后: %s\n", input);

}