# include "stdio.h"


// 接收一个数组形参, 长度, 描述
void show1(int arr[], int len, char * desc){
    printf("%s\n", desc);
    for (int i=0; i<len; i++)
        printf("%d  ", arr[i]);
    printf("\n");
}


// 接收一个指针形参, 长度, 描述
void show2(int * arr, int len, char * desc){
    printf("%s\n", desc);
    for (int i=0; i<len; i++)
        printf("%d  ", *(arr + i));
    printf("\n");
}


int main(){
    
    int a[4] = {1, 2, 3, 4}, * pt_a;
    pt_a = &a[0];   // 指向第一个数组元素

    char * desc = "实参是数组名, 形参是数组名 show1(a, 4, desc);";
    show1(a, 4, desc);

    desc = "实参是数组名, 形参是指针变量名 show2(a, 4, desc);";
    show2(a, 4, desc);

    desc = "实参是指针变量名, 形参是指针变量名 show2(pt_a, 4, desc);";
    show2(pt_a, 4, desc);

    desc = "实参是指针变量名, 形参是数组名, show1(pt_a, 4, desc);";
    show1(pt_a, 4, desc);

    return 0;
}

