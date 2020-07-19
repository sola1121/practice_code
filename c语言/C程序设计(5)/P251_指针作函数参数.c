# include "stdio.h"


// 使用指针, 遍历二维数组
void output_array(float (*p)[4], int row){
    /*
        通过行和列来遍历. 
        float(*)[4] 是一个可以容纳4个float元素的指针, 以此来指向二维数组的每行, 即一维数组.
        其存储的地址是实参的地址, 即nums[0]的起始地址
    */
    for(int r=0; r<row; r++){
        for(int c=0; c<4; c++){
            printf("%5.1f ", *(*(p+r)+c));
        }
        printf("\n");
    }
}


// 通过遍历数组, 求平均值
void average(float *p, int n){   // 定义求平均的函数
    float *p_end, 
          sum=0,
          aver;
    
    p_end = p + n - 1;   // n的值为12时, p_end的值是p+11, 指向最后一个元素
    for(; p<=p_end; p++)   // p_end为指向最后一个元素的指针, 是数组中地址最大的
        sum = sum + (*p);
    aver = sum / n;
    printf("average=%5.2f\n", aver);
}


// 输出数组中给定下标的内容
void search(float (*p)[4], int n){   // p是指向具有4个元素的一维数组的指针
    int i;
    printf("数组元素位 %d:\n", n);
    for(i=0;i<4;i++)
        printf("%5.2f ", *(*(p+n)+i));
    printf("\n");
}


// 遍历找出小于limit的值
void search2(float (*p)[4], int rw, int col){  // 形参p是指向包含4个float型元素的一维数组的指针变量
    const int limit = 70;
    int flag=0;
    for(int r=0; r<rw; r++){
        for(int c=0; c<col; c++){
            if ( *(*(p+r)+c) < limit) flag = 1;   // *(*(p+r)+c)就是p[r][c]
            if (flag == 1){
                printf("行号: %d, 列数: %d 元素小于限制值, 为%5.1f.\n", r+1, c+1, *(*(p+r)+c));
                flag = 0;
            }
        }
    }
}


int main(){
    float nums[3][4] = {{65, 67, 70, 60}, {80, 87, 90, 81}, {90, 99, 100, 98}};
    output_array(nums, 3);
    average(*nums, 12);   // 实参*nums, 即nums[0]也就是&nums[0][0]
    search(nums, 2);   // 形参float (*)[4]接受一个四元素的一维数组
    search2(nums, 3, 4);

    return 0;
}

/*
    search中, 形参p的类型是float(*)[4], 它不是指向整型变量的指针变量, 而是指向包含4个元素的一维数组的指针变量. 
    函数调用开始时, 将实参nums的值(代表该素组0行起始地址)传给p, 使p也指向nums[0].
    p+n是nums[n]的起始地址, *(p+n)+i是nums[n][i]的地址, *(*(p+n)+i)是nums[n][i]的值.
*/