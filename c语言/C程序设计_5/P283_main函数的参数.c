# include "stdio.h"

/*
    main函数的参数是由操作系统给出的. 在操作命令状态下, 实参是和执行文件的命令一起给出的.
    命令行的一般形式为: 命令名 参数1 参数2 ... 参数n
    命令名和参数之间用空格分隔. 命令名是可执行文件名(此文件包含main函数), 调用如: file.exe "args1" "args2"
*/

// argc (argument count)表示参数个数, argv(argument vector)参数向量
// 参数向量是一个*char指针数组, 数组中每一个元素(其值为指针)指向命令行中的一个字符串首字符
int main(int argc, char *argv[]){
    printf("参数个数: %d\n", argc);
    
    char* *ppt;
    ppt = argv;
    for (int i=0; i<argc; i++)
        printf("参数向量: %s\n", *(argv+i));

    return 0;
}

/*
    更加精简的遍历

    int main(int argc, char * argv){
        while(argc>1){
            ++argv;
            printf("%s\n", *argv);
            --argc;
        }

        return 0;
    }


    int main(int argc, char * argv){
        while(argc-->1)   // while(--argc>0)
            printf("%s\n", *++argv);

        return 0;
    }


    配合系统echo命令

    int main(int argc, char * argv[]){
        while(--argc>0)
            printf("%s%c", *++argv, (argc>1?'':'\n));
        
        return 0;
    }

    
    int main(int argc, char * argv[]){
        int i;
        for (i=0; i<argc; i++)
            printf("%s%c", argv[i], (i<argc-1?'':'\n'));

        return 0;
    }
*/