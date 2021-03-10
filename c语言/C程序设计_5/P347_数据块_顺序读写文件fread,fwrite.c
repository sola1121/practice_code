# include "stdio.h"
# include "string.h"
# include "stdlib.h"

/*
从文件中读取块数据
size_t fread(void * ptr, size_t size, size_t count, FILE * stream)
ptr 是一个内存区块的指针, 可以是变量, 数组, 结构体等. 对fread来说, 用来存放读取到的数据.
size 要读写的字节数
count 要读写多少个数据项, 每个数据项的长度为size
stream FILE类型指针

从文件中写入块数据
size_t fwrite(const void * ptr, size_t size, size_t count, FILE * stream)
ptr 是一个内存区块的指针, 可以是变量, 数组, 结构体等. 对fwrite来说, 用来存放将要写入的数据.
size 要读写的字节数
count 要读写多少个数据项, 每个数据项的长度为size
stream FILE类型指针

理论上, 每次读写 size*count 个字节的数据.

size_t 是在 <stdio.h> 和 <stdlib.h> 头文件中使用 typedef 定义的数据类型, 表示无符号整数, 也即非负数, 常用来表示数量. 

返回值: 返回成功读写的块数, 也即 count. 
       如果返回值小于 count: 
        对于 fwrite() 来说, 肯定发生了写入错误, 可以用 ferror() 函数检测. 
        对于 fread() 来说, 可能读到了文件末尾, 可能发生了错误, 可以用 ferror() 或 feof() 检测. 

int ferror (FILE * stream) 返回文件指针错误

如果将stream改为stdin, 那么fread也可以作为输入方法. 
如若此, 那么其将会读取size*count个字节才会停止读取, 如果输入有空格, 换行符, 则一样读取并储存.

*/

# define LEN 32

struct Info{
    int num;
    char string[64];
};


char * generate_string(){
    int i = 0, length = 0;
    length = rand()%31+1;
    static char string[32];   // 字符串
    while (i<length) {
        string[i] = rand()%26+97;
        i++;
    }
    string[length] = '\0';
    return string;
}


void output_info(struct Info *content){
    for (int i=0; i<LEN; i++)
        printf("%d, %s\n", (content+i)->num, (content+i)->string);
}


int main(){
    struct Info content[LEN], output[LEN];

    for (int i=0; i<LEN; i++){
        (content + i)->num = i;
        strcpy((content + i)->string, generate_string());
    }
    puts("将写入的内容.");
    output_info(content);
    
    char *filepath = "./do_not_push_test.txt";
    const int SIZE = sizeof(struct Info);   // 4 + 64 = 68
    const int COUNT = 1;
    size_t flag = 0;
    FILE *fp;

    puts("文件以二进制的形式写入\n");
    if ((fp=fopen(filepath, "wb"))==NULL){
        puts("文件打开失败.\n");
        exit(0);
    }
    
    // 写入操作
    for(int i=0; i<LEN; i++){
        flag = fwrite(content + i, SIZE, COUNT, fp);   // fwrite(&contentp[i], sizeof(struct Info), 1, fp); 一个元素一个元素的写入 fp指向文件中
        if (flag < COUNT) printf("第%d 写入文件时出错. CODE:%d", i+1, ferror(fp));
    }

    fclose(fp);

    puts("从二进制文件中读取.");
    if ((fp=fopen(filepath, "rb"))==NULL){
        puts("文件打开失败.\n");
        exit(0);
    }

    // 读取操作
    for (int i=0; i<LEN; i++){
        flag = fread(output + i, SIZE, COUNT, fp);   // fread(&content[i], sizeof(struct Info), 1, fp); 一个一个元素的读取 到output中
        if (flag < COUNT) printf("第%d 读入文件时出错. CODE:%d", i+1, ferror(fp));
    }

    output_info(output);
    fclose(fp);

    return 0;
}
