# include "stdio.h"

/*

array是一个二维数组, 则 array 变量名指向它的起始地址 array[0][0]

二维数组名(如array)是指向行(一维数组)的. 因此array+1中的1代表一行中全部元素所占的字节数.
一维数组名(如array[0],array[1])是指向列元素的. array[0]+1中的1代表一个array元素所占的字节数.

array和array+1是指向行的指针, 在指向行的指针前面加一个*就是*array和*(array+1), 它们就成为指向列的指针, 
分别指向array数组的0行0列的元素和1行0列的元素.

反之, 在指向列的指针前面加&, 就成为指向行的指针.
例如array[0]是指向0行0列元素的指针, 在其前加一个&, &array[0], 
由于array[0]与*(array+0)等价, 因此&array[0]与&*array等价, 也就是与array等价, 它指向俄日为数组的0行.

注意:
    不要把&array[i]简单地理解为array[i]元素的存储单元的地址, 因为并不存在array[i]这样一个实际的数据存储单元.
    它只是一种地址的计算方法, 能得到第i行的起始地址, &array[i]和array[i]的值是一样的, 但它们的基本类是不同的.
    &array[i]或array+i指向行, 而array[i]或*(array+i)指向列.
    当列下标j为0时, &array[i]和array[i](即array[i]+j)值相等, 即它们的纯地址相同, 
    但应注意它们所指向的对象的类型是不同的, 即指正类型的基本类型不一样.
    *(array+i)只是array[i]的另一种表示形式, 不要简单地认为*(array+i)是"array+i所指单元中的内容".
    在一维数组中array+i所指的是一个数组元素的存储单元, 在该单元中有具体值, 这样说是正确的. 而对于二维数组, 
    array+i不是指向具体存储单元而是指向行(即指向一维数组). 
    在二维数组中, array+i, array[i], *(array+i), &array[i], &array[i][0]的值相等, 即它们都代表同一地址, 但基本类型不同.

array                                       二维数组名, 指向因为数组array[0], 即0行起始地址
array[0], *(array+0), *array                0行0列元素地址
array+1, &array[1]                          1行起始地址
array[1], *(array+1)                        1行0列元素array[1][0]的地址
array[1]+2 *(array+1)+2, &array[1][2]       1行2列元素a[1][2]的地址
*(array[1]+2), *(*(array+1)+2), array[1][2] 1行2列元素array[1][2]的值

理解*(*(array+1)+2), array+1, 在原地址上增加类型单位的字节数, 变为下一个元素的地址, 
                    *(array+1), 解析当前地址, 但因为array是一个二维数组, 返回的是行array[1], 也是地址
                    *(array+1)+2, 行地址上增加类型单位的字节数, 指向了&array[1][2]
                    *(*(array+1)+2), 获取地址的内容

*/

int main(){
    int arr[3][4] = {
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 34}
    },

    arr2[3][4] = {11, 12, 13, 14, 21, 22, 23, 24, 31, 32, 33, 34};   // 与arr一样
    
    int *arr3 = arr;   // 让一个指针指向arr的位置, arr本身就是一个指针, 可以直接指针赋值
    
    printf("%x, %x\n", arr, *arr);   // 0行起始地址 和 0行0列元素地址
    printf("%x, %x\n", arr[0], *(arr+0));   // 0行0列元素地址
    printf("%x, %x\n\n", &arr[0], &arr[0][0]);   // 0行起始地址 和 0行0列元素地址
    
    printf("%x, %x\n", arr[1], arr+1);   // 1行0列元素地址 和 1行起始地址
    printf("%x, %x\n", &arr[1][0], *(arr+1)+0);   // 1行0列元素地址
    printf("%x, %x\n", arr[2], *(arr+2));   // 2行0列元素地址
    printf("%x, %x\n\n", &arr[2], arr+2);   // 2行起始地址

    printf("%d, %d\n", arr[1][0], *(*(arr+1)+0));   // 1行0列元素的值
    printf("%d, %d\n", *arr[2], *(*(arr+2)+0));   // 2行0列元素的值
    printf("%d, %d\n", *arr[2], *(*(arr+2)));   // 2行0列元素的值

    printf("\narr与arr2比较同位元素true==%d\n", arr[2][0]==arr2[2][0]);
    printf("直接比较, 但这二者皆是不同的地址, 肯定为false==%d, &arr[0][0]=%p, &arr2[0][0]=%p\n", arr==arr2, arr, arr2);
    printf("通过赋值获得的arr3, arr3=%p arr=%p\n", arr3, arr);

    return 0;
}