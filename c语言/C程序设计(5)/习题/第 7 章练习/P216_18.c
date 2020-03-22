#include "stdio.h"
#include "time.h"


int main(){
    time_t now;
    double seconds;
    struct tm timeinfo, start;
    unsigned short int year=2019, month=12, date=9;
    // printf("输入 年: \n");
    // scanf("%d", &year);
    // printf("输入 月: \n");
    // scanf("%d", &month);
    // printf("输入 日期: \n");
    // scanf("%d", &date);

    time(&now);

    timeinfo = *localtime(&now);
    timeinfo.tm_year = year;
    timeinfo.tm_mon = month;
    timeinfo.tm_mday = date;

    start = *localtime(&now);
    start.tm_year = year;
    start.tm_mon = 1;
    start.tm_mday = 1;

    seconds = difftime(mktime(&timeinfo), mktime(&start));
    printf("此年已经走过 %.2lf 天了.\n", seconds/3600/24);

    return 0;
}