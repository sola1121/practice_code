# include "stdio.h"

/*
    将尝试把指针变量使用二进制方式导出到文件, 然后在导入

    导出的文件内容为 48 00 00 00 EOF (十六进制, 小端排), 正好是72, 8位字节

    也就是可以使用指针直接导出指向的内容

    然后可以使用变量(需要使是分配了内存的), 将数据导入
*/

int main(int args, char *argv[]){
    const char * const filepath = "./测试指针的导出与导入.dat";

    int num = 72, *pt = NULL;
    pt = &num;

    FILE *fp = NULL;

    fp = fopen(filepath, "wb");
    if (fp != NULL){
        fwrite(pt, sizeof(int), 1, fp);
    }
    fclose(fp);

    int r_num = 0;
    fp = fopen(filepath, "rb");
    if (fp != NULL){
        fread(&r_num, sizeof(int), 1, fp);
        printf("导入 %d\n", r_num);
    }

    return 0;
}
