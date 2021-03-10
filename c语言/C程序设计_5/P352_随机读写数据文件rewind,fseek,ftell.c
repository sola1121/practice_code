# include "stdio.h"
# include "stdlib.h"

/*
文件位置标志
系统为了对读写进行控制, 为每个文件设置了一个文件位置读写标记, 用来指示 接下来要读写的下一个字符的位置. 
每一次读写, 文件读写标志都会向前进位.
在FILE结构体的定义中, 可以发现有一个 unsigned char * curp; 这就使文件位置标记(编译器的不同定义也不同)

void rewind(FILE * stream)
使文件位置标志重新回到文件头

int fseek(FILE * stream, long  off, int  whence)
stream 文件类型指针
off 位移量, 其是指以起始点为基点, 向前移动的字节数. 其数据类型是long, 数字常量后面加L就可以规定为long
whence 从哪里, 即起始点, 用0 SEEK_SET表示文件开始的位置, 1 SEEK_CUR 表示文件当前的位置, 2 SEEK_END表示文件末尾的位置

long ftell(FILE * stream)
得到流式文件中文件位置标记的当前位置

*/


void output_file(FILE *fp, int n){
    printf("\n将读取 %d 个字符\n", n);
    char ch = 0;
    do {
        ch = getc(fp);
        putchar(ch);
        n --;
    } while (n>0);
    putchar(10);
}


int main(int args, char * argv[]){
    int seek_return = 0;
    char *filepath = "./C_log.svg";
    FILE *fp;
    if ((fp=fopen(filepath, "r"))==NULL){
        puts("文件打开失败.\n");
        exit(0);
    }
    output_file(fp, 64);

    printf("->当前ftell(fp) %ld\n", ftell(fp));   // 使用ftell获取文件位置标记

    rewind(fp);   // 使用rewind将文件位置标记重新指向文件开头

    printf("->调用rewind(fp), 当前ftell(fp) %ld\n", ftell(fp));

    output_file(fp, 10);
    
    // 在已经读取了10个字符的情况下, 标记继续向后移动20, 将会从30字符开始
    seek_return = fseek(fp, 20l, SEEK_CUR);
    printf("->调用fseek(fp, 20, SEEK_CUR) 返回 %d, 当前ftell(fp) %ld\n", seek_return, ftell(fp));
    
    // 在当前30字符, 向亲移动5, 变为25字符
    seek_return = fseek(fp, -5, SEEK_CUR);
    printf("->调用fseek(fp, -5, SEEK_CUR) 返回 %d, 当前ftell(fp) %ld\n", seek_return, ftell(fp));
    
    // 在当前25字符, 向前移动100, 返回-1, 执行失败, 依然在25字符
    seek_return = fseek(fp, -100, SEEK_CUR);
    printf("->调用fseek(fp, -100, SEEK_CUR) 返回 %d, 当前ftell(fp) %ld\n", seek_return, ftell(fp));

    // 从字符开头, 向后移动64, 将会从64字符开始
    fseek(fp, 64, SEEK_SET);
    printf("\n->调用fseek(fp, 64, SEEK_SET), 当前ftell(fp) %ld\n", ftell(fp));

    output_file(fp, 32);

    // 从字符结束, 向前移动128. 注意, 这里如果继续向后移动, 也可以, 不会报错, 但是打印出来的就不知道使哪里的东西了
    fseek(fp, -128, SEEK_END);
    printf("\n->调用fseek(fp, -128, SEEK_END), 当前ftell(fp) %ld\n", ftell(fp));

    output_file(fp, 128);

    /*
    fp = freopen(filepath, "rb", fp);
    上面的使用r文本打开, 但是因为使svg文件, 也没什么换行符, 用r和rb都是一样的
     */

    // fseek()实现跳数据块
    char ch = 0;
    size_t chunk = 0;
    for (int i=0; i<64; i+=2){
        fseek(fp, i*sizeof(char), SEEK_SET);   // 按照每个 字符的大小 * 个数 移动文件位置指针
        chunk = fread(&ch, sizeof(char), 1, fp);   // 读取 size * count字节的数据
        if (i==0) printf("通过fseek与fread读取数据块, 数据块大小: %lu 字节\n", chunk);
        putchar(ch);
    }
    putchar(10);

    fclose(fp);

    return 0;
}