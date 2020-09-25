# include "stdio.h"


int main(){
    short num_month=0;
    char * monthes[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "Devember"
    };

    printf("输入月份数: ");
    scanf("%hd", &num_month);

    if (num_month<=0 || num_month>=13){
        printf("Error, 数字超出月份范围.\n");
        return 1;
    }

    printf("对应的月份: %s\n", *(monthes+--num_month));

    return 0;
}