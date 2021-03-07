# include "stdio.h"

/*
    类型名 * 函数名(参数列表)
*/


float * array_traversal(float(* pointer)[4], int i){   // 接收一个包含四个元素的float数组
    float * p;   // 将返回的指针变量
    p = *(pointer+i);   // 形参pointer是指向包含四个float元素的一维数组的指针变量
    return p;   // p的值是&matrix[m][0]
}


float * search(float (*pointer)[4]){    // 形参pointer是指向具有四个float元素的以为数组的指针变量
    const float limit = 60.0;
    int i=0;
    float * p;   // 将返回的指针变量
    p = NULL;
    for (; i<4; i++)   // 遍历一维数组
        if (*(*pointer+i)<limit)   // 如果有小于限制值的, 使p指向metrix[i][0]
            p = *pointer;
    return p;
}


int main(){
    float matrix[][4] = {{60, 73, 81, 90}, {88, 65, 57, 90}, {45, 78, 99, 67}};
    float *pt;
    int m, n;

    printf("输入数列标号: ");
    scanf("%d", &m);
    if (m!=0 && m!=1 && m!=2){
        printf("标号超过理解范围. 退出.\n");
        return 0;
    }
    printf("标号 %d 的数列中存储了: ", m);

    pt = array_traversal(matrix, m);   // 调用array_traversal函数, 返回matrix[m][0]的地址

    for (n=0; n<4; n++)
        printf("%5.2f\t", *(pt+n));   // 输出matrix[m][0]~matrix[m][3]的值

    printf("\n\n有少于limit的值的一维数组: \n");

    for (m=0; m<3; m++){   // 遍历行
        pt = search(matrix+m);   // 调用search函数, 如果有不满足limit的, 返回matrix[m][0]的地址, 就是一维数组地址
        if (pt == *(matrix+m)){   // 如果返回的是matrix[m][0]的地址, 表示pt的值不是NULL
            for (n=0; n<4; n++)   // 遍历列
                printf("%5.2f  ", *(pt+n));   // 输出matrix[m][0]~matrix[m][0]的值
            printf("\n");
        }
    }

    return 0;
}