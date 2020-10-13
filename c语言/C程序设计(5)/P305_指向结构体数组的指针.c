# include "stdio.h"


# define len 3

struct Student {
    long ID;
    char name[32];
    unsigned short gender;
    unsigned short age;
};

struct Student stu_array[3] = {
    {1101101, "人1", 0, 21},
    {1201102, "人2", 1, 18},
    {1301103, "人3", 0, 22}
};

int main(){
    struct Student *p_stu;

    for (p_stu=stu_array; p_stu<stu_array+3; p_stu++){
        printf("%ld %s, %s, %d\n", 
                p_stu->ID, p_stu->name, p_stu->gender==0?"female":"male", p_stu->age);
    }

    return 0;
}