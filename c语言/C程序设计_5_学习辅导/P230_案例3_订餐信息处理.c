# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"
# include "iso646.h"

/*
    使用一个链表, 单独的保存各个点餐订单
    实现增删改查, 实现显示,完成,导出,导入功能
*/

# define FILEPATH "./orders_content.dat"
# define CURR_CONTENT curr->id, curr->name, curr->people_number, curr->dinner_time, curr->is_done


const char * output_title = "订单编号,点餐人名,用餐人数,用餐时间,是否完成\n";
const char * output_content = "%u,%s,%u,%s,%d\n";
const char * output_format = "订单编号: %u, 点餐人名: %s, 用餐人数: %u, 用餐时间: %s, 是否完成: %d\n";


struct _GuestOrder{
    unsigned int id;   // 编号
    char name[16];   // 点餐人名
    unsigned short people_number;   // 用餐人数
    char dinner_time[32];   // 用餐时间
    short is_done;   // 订单完成
    struct _GuestOrder * next;   // 指向后一个结构体变量
};

typedef struct _GuestOrder GuestOrder;


// 增 订餐信息
GuestOrder * insert_guest(GuestOrder * head){
    unsigned int count = 1;
    GuestOrder *newone = (GuestOrder *) malloc(sizeof(GuestOrder)),
               *curr = head;
    // head 为空, 即还没有内容
    if (curr == NULL){
        printf("当前订单编号 %d\n", count);
        newone->id = count;
        newone->next = NULL;
        head = newone;
    // head 不为空
    } else {
        while (curr->next != NULL){   // 用来将curr 当前节点指向链表最后, 并计数用来表示编号
            curr = curr->next;
            ++count;
        }
        printf("当前订餐编号 %d\n", count+=1);
        newone->id = count;
        newone->next = NULL;
        curr->next = newone;
    }
    printf("点餐人名: "); scanf("%s", newone->name);
    printf("用餐人数: "); scanf("%hd", &newone->people_number);
    printf("用餐时间: "); scanf("%s", newone->dinner_time);

    return head;
}


// 删 订餐信息, 可以通过id, name来进行删除
GuestOrder * delete_guest(GuestOrder *head){
    unsigned int d_id = 0;
    char d_name[16] = "\0";
    printf("输入要删除的订单编号(0跳过): "); scanf("%u", &d_id);
    printf("输入要删除的用餐人名(s跳过): "); scanf("%s", d_name);
    if (strcmp(d_name, "s")==0)
        strcpy(d_name, "\0");

    GuestOrder *prev = head, *curr = head;
    
    while (curr != NULL){
        if (curr->id==d_id or strcmp(curr->name, d_name)==0){
            puts("将删除:");
            printf(output_format, CURR_CONTENT);
            if (curr==head){
                head = head->next;
            } else {
                prev->next = curr->next;            
            }
            puts("成功.");
        }
        prev = curr;
        curr = curr->next;
    }

    return head;
}


// 改 订餐信息, 通过id来进行更改, 输入id后要求输入新的内容
GuestOrder * update_guest(GuestOrder *head){
    unsigned int aim_id = 0;
    printf("\n输入要更改的订单编号: "); scanf("%u", &aim_id);
    if (aim_id <= 0)
        puts("Warning, 编号数必须使大于0的整数.");

    char new_name[16] = "\0", new_dinner_time[32] = "\0";
    unsigned short new_people_number = 0;
    unsigned int count = 0;
    GuestOrder * curr = head;
    while (curr != NULL){
        if (curr->id == aim_id){
            printf(output_format, CURR_CONTENT);
            printf("新的点餐人名(s跳过): "); scanf("%s", new_name);
            if (strcmp(new_name, "s") != 0){
                strcpy(curr->name, new_name);
            }
            printf("新的用餐人数(0跳过): "); scanf("%hd", &new_people_number);
            if (new_people_number != 0){
                curr->people_number = new_people_number;
            }
            printf("新的用餐时间(s跳过): "); scanf("%s", new_dinner_time);
            if (strcmp(new_dinner_time, "s") != 0){
                strcpy(curr->dinner_time, new_dinner_time);
            }
            return head;
        }
        count += 1;
        curr = curr->next;
    }
    printf("\n编号数超出范围, 最大 %d\n", count);

    return head;
}


// 查 订餐信息, 可以通过id, name来进行查询
void query_guest(GuestOrder *head){
    unsigned int q_id = 0;
    char q_name[16] = "\0";
    printf("输入要查找的订单编号(0跳过): "); scanf("%u", &q_id);
    printf("输入要朝找的用餐人名(s跳过): "); scanf("%s", q_name);
    if (strcmp(q_name, "s")==0)
        strcpy(q_name, "\0");

    int count = 0;
    GuestOrder *curr = head;

    while (curr != NULL){
        if (curr->id == q_id or strcmp(curr->name, q_name)==0){
            printf(output_format, CURR_CONTENT);
            count += 1;
        }
        curr = curr->next;
    }
    printf("\n共有结果: %d条\n\n", count);
}


// 显示 订餐信息
void show_all(GuestOrder *head){
    unsigned int count = 0;
    GuestOrder *curr = head;
    printf(output_title, NULL);
    while (curr != NULL){
        printf(output_content, CURR_CONTENT);
        curr = curr->next;
        count += 1;
    }
    printf("共有 %u 条数据.\n", count);
}


// 订餐信息完成, 输入
GuestOrder * complete_order(GuestOrder *head){
    unsigned int complete_id = 0;
    printf("\n输入要更改的订单编号: "); scanf("%u", &complete_id);
    if (complete_id <= 0)
        puts("Warning, 编号数必须使大于0的整数.");

    unsigned int count = 0;
    GuestOrder * curr = head;

    while (curr->next == NULL){
        if (curr->id == complete_id){
            curr->is_done = 1;
            printf("完成订单 ");
            printf(output_format, CURR_CONTENT);
            return head;
        }
        count += 1;
    }

    printf("共查询 %d 条数据, 未找到符合订单编号.\n", count);
    return head;
}


// 导出 订餐信息
int export_orders(GuestOrder *head){
    FILE *fp = NULL;
    if ((fp = fopen(FILEPATH, "wb")) == NULL) {
        perror("文件打开失败.");
        return 1;
    }

    GuestOrder *curr = head;
    unsigned int count = 0, sucss = 0;

    while (curr != NULL){
        sucss += fwrite(curr, sizeof(GuestOrder), 1, fp);
        curr = curr->next;
        count += 1;
    }
    fclose(fp);
    printf("共处理 %d 条数据, 成功导出 %d\n", count, sucss);

    return 0;
}

// 导入 订餐信息, 将文件中的导入到已有head尾节点的后面
GuestOrder * import_orders(GuestOrder *head){
    FILE *fp = NULL;
    if ((fp = fopen(FILEPATH, "rb")) == NULL){
        perror("文件打开失败.");
        return NULL;
    }

    GuestOrder *getone = NULL, *prev = head, *curr = head;
    unsigned int already_count = 0, total_count = 0, sucss_count = 0, sucss = 0;

    // 将curr指向head尾节点
    while (head != NULL and curr->next != NULL){   // 当条件head!=NULL没满足的时候就不会执行了, 如果两个交换位置, 会报错, 因为NULL没有next
        already_count += 1;
        curr = curr->next;
        if (curr->next == NULL)
            already_count += 1;
    }
    printf("当前已有 %d 条数据.\n", already_count);

    // 开始读取文件中的内容, 然后导入到一个新地址, 最后接在curr后面
    while (!feof(fp)){
        getone = (GuestOrder *) malloc(sizeof(GuestOrder));   // 避免重复使用同一个地址, 要不断的开辟新内存空间以便存储数据
        sucss = fread(getone, sizeof(GuestOrder), 1, fp);

        //NOTE : 解决读取EOF的问题, 当没有读取指定大小的时候, 返回的数据个数是0
        if (sucss == 0){
            if (total_count > sucss_count)
                perror("读取过程中出现错误.");
            break;
        }

        getone -> next = NULL;   // 清除上一个链表next的值
        //NOTE : 将prev指向当前, 当前指向新获取的数据, prev->next指向当前, 完成向链表中加数据
        prev = curr;
        // curr为head,且该head还没内容, 将当前读取的内容设置为head
        if (curr == head and curr == NULL){
            prev = getone;
            curr = getone;
            head = getone;
        // 使用prev进行链接
        } else {
            curr = getone;
            prev->next = curr;
        }

        sucss_count += sucss;
        total_count += 1;
    }
    fclose(fp);
    printf("读取 %d 条数据, 成功导入 %d\n", total_count, sucss_count);

    return head;
}


// 打印菜单
void menu(){
    puts("\n选择下面选项进行操作");
    puts("1---插入(Insert)");
    puts("2---删除(Delete)");
    puts("3---修改(Update)");
    puts("4---查询(Query)");
    puts("5---显示(Show)");
    puts("6---完成(Complete)");
    puts("7---导出(Export)");
    puts("8---导入(Import)");
    puts("9---退出(Exit)");
}


int main(int args, char *argv[]){

    int flag = 0;
    GuestOrder *head = NULL, *temp = NULL;

    while (1){
        menu();
        printf("选择序号: "); scanf("%d", &flag);
        switch (flag){
        case 1:
            head = insert_guest(head);
            break;
        case 2:
            head = delete_guest(head);
            break;
        case 3:
            head = update_guest(head);
            break;
        case 4:
            query_guest(head);
            break;
        case 5:
            show_all(head);
            break;
        case 6:
            head = complete_order(head);
            break;
        case 7:
            export_orders(head);
            break;
        case 8:
            head = import_orders(head);
            break;
        case 9:
            puts("程序退出.");
            exit(0);
            break;
        default:
            puts("未确认命令, 请重新输入.");
            break;
        }
    }

    return 0;
}