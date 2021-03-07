# include "stdio.h"


struct Date{
    unsigned short year;
    unsigned short month;
    unsigned short day;
};


int main(){
    struct Date d = {2020, 12, 30};

    unsigned int total_days = 0;

    // 平闰年判断
    unsigned short month_2 = 29;
    if (d.month>2){
        if (d.year%4 != 0 || d.year%100 !=0 || d.year %400 != 0)
            month_2 = 28;    
    }
    // 按月计算天数
    for (int m=1; m<d.month; m++){
        if (m == 2){
            total_days += month_2;
        } else {
            if (m%2==0){
                total_days += 30;
            } else {
                total_days += 31;
            }
        }
    }
    total_days += d.day;

    printf("%d-%d-%d 是本年中的第 %d天.\n", d.year, d.month, d.day, total_days);

    return 0;
}