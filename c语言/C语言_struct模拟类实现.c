# include "stdio.h"
# include "string.h"
# include "stdbool.h"

# define CONT_LEN 1024


// 将被用来模拟类的结构体
struct String {
    char content[CONT_LEN]; 
    bool (*set)(struct String*, char s[CONT_LEN]);   // 赋值
    bool (*put)(struct String*, struct String);   // 将值赋值给同类型的对象
    bool (*compare)(struct String*, struct String);   // 同类型字符比对
    char * (*append)(struct String*, struct String);   // 字符串拼接
    unsigned int (*length)(struct String*);   // 返回长度
    void (*repr)(struct String*);   // 打印内容
};


bool set(struct String *self, char * s){
    if (strnlen(s, CONT_LEN+2) > CONT_LEN)
        perror("Error, 赋值超出容量.");
    if (strcpy(self->content, s))
        return true;
    return false;
}


bool put(struct String *self, struct String other){
    set(self, other.content);
}


bool compare(struct String *self, struct String other){
    if (strcmp(self->content, other.content)==0)
        return true;
    else 
        return false;
}


char * append(struct String *self, struct String other){
    if (CONT_LEN - self->length(self) < other.length(&other)){
        perror("Error, 赋值长度超出容量.");
        return NULL;
    }
    if (strcat(self->content, other.content)){
        return self->content;
    }
    return NULL;
}


unsigned int length(struct String *self){
    return strlen(self->content);
}


void repr(struct String *self){
    printf("<object StringClass> content %s\n", self->content);
}


// 定义类名称
typedef struct String StringClass;


// 构造函数, 当然也可以像上面那样把该构造写入struct String 中
void construct(StringClass * self){
    self->set = set;
    self->put = put;
    self->compare = compare;
    self->append = append;
    self->length = length;
    self->repr = repr;
}


int main(int args, char * argv[]){
    
    StringClass obj_s1, obj_s2;

    // 调用模拟构造函数
    construct(&obj_s1);
    construct(&obj_s2);

    obj_s1.set(&obj_s1, "模拟类s1的内容");
    obj_s2.set(&obj_s2, "模拟类s2的内容");


    obj_s1.repr(&obj_s1), obj_s2.repr(&obj_s2);

    printf("obj_s1 内容的长度: %u\n", obj_s1.length(&obj_s1));
    printf("obj_s2 内容的长度: %u\n", obj_s2.length(&obj_s2));

    printf("对比obj_s1与obj_s2 的内容: %s\n", obj_s1.compare(&obj_s1, obj_s2)?"相同":"不同");

    printf("拼接obj_s1与obj_s2 的内容: %s\n", obj_s1.append(&obj_s1, obj_s2));

    return 0;
}