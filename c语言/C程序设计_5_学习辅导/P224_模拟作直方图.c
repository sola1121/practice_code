# include "stdio.h"


/*
    提取书上的例子, 跑不通
*/

void draw(int grade[]){
    int i, j, max, k, temp, x;
    char screen [22][44];   // 定义一个字符型数组,用来表示屏幕输出
    // printf("\n模拟直方图\n");

    max = grade[0];

    for (i=1; i<=10; i++)   // 寻找分数段中人数最多的
        if (grade[i]>max) max = grade[i];

    for (i=1; i<=10; i++)   // 计算显示时, 应该输出的 *号个数
        grade[i] = (int)(20.0*grade[i]/max + .5);

    for (i=0; i<=41; i++)   // 先将输出的所有点清零
        for (j=0; j<=41; j++)
            screen[i][j] = 0;
    
    // 画 X轴
    for (i=0; i<=41; i++)
        screen[21][i] = '-';
    screen[21][41] = 'X';
    // 画 Y轴
    screen[0][0] = 'Y';
    for (i=1; i<21; i++)
        screen[i][0] = '|';
    
    // 将符合条件的点(x, y)赋值为 *号
    k = 1;
    for (x=1; x<=10; x++, k=k+4){   // x控制输出的行, k控制输出的列
        temp = grade[x];   // temp 取分数的值
        if (temp != 0)   // 分数不为 0, 赋值*号
            for(i=1; i<=temp; i++){  
                for (j=1; j<=4; j++)   // 该分数段的每行对应4个*号
                    screen[20-i+1][j+k] = '*';
            }
    }

    // 输出数组, 在屏幕上画图
    for (i=0; i<=21; i++){
        for (j=0; j<=41; j++)
            if (screen[i][j]!=0)   // 数组内容不为0, 输出数组中的内容
                printf("%c", screen[i][j]);
            else printf(" ");
        putchar('\n');
    }

    printf("0 10 20 30 40 50 60 70 80 90 100\n");

    getchar();
}


int main(void){
    int grade[11] = {45, 68, 57, 78, 89, 88, 82, 74, 54, 65, 71};

    draw(grade);

    return 1;
}