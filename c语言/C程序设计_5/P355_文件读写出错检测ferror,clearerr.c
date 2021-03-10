# include "stdio.h"
# include "stdlib.h"

/*
int ferror(FILE *stream)
返回流文件的错误指示, 无错0, 有错1或其他非零

void clearerr(FILE *stream)
使文件错误指示重新变为0

如果在调用一个输入输出函数时出现错误, ferror()数值为一个非零值. 
若在之后的文件操作中, 使用同一个文件指针, 应该先将文件错误指示重新变为0, 然后在进行下一个文件操作, 在用ferror看是不是有误

文件错误指示只要有了, 就会一直保留在FILE指针中, 指导对同一指针使用clearerr或rewind或任何其他一个输入输出函数.

*/


int main(int args, char * argv[]){
    size_t chunk = 0;
    char * filepath = "./do_not_push_test.txt";
    FILE * fp = NULL;

    // 写文件打开
    if ((fp=fopen(filepath, "wb"))==NULL){
        perror("文件打开失败.\n");
        exit(0);
    }

    char content[6][6] = {"1", "22", "333", "4444", "55555", "666666"};

    for (int i=0; i<6; i++){
        chunk = fwrite(content + i, 6, 1, fp);
    }
    printf("当前文件位置标记ftell(fp) %ld\n", ftell(fp));
    printf("在-写-状态下的fwrite(), 返回每次写入的数据块大小 size*count = %lu \n", chunk);
    printf("这时的ferror(fp)返回的状态码是%d\n", ferror(fp));
    putchar(10);

    // 改为读文件打开
    fp = freopen(filepath, "rb", fp);

    char ch = '\n';
    chunk = fwrite(&ch, sizeof(char), 1, fp);   // 再向其中写入数据, 将会出错

    printf("当前文件位置标记ftell(fp) %ld\n", ftell(fp));
    printf("在-读-状态下的fwrite(), 返回每次写入的数据块大小 size*count = %lu \n", chunk);   // 0
    printf("这时的ferror(fp)返回的状态码是%d\n", ferror(fp));   // 1
    putchar(10);

    char str[6] = "";
    chunk = fread(str, sizeof(str), 1, fp);
    printf("读取数据块大小 size*count = %lu, 数据内容: ", chunk);
    puts(str);

    // 清除文件出错
    clearerr(fp);
    printf("当前文件位置标记ftell(fp) %ld\n", ftell(fp));
    printf("使用clearerr(fp)后, 这ferror(fp)返回的状态码是%d\n", ferror(fp));

    return 0;
}