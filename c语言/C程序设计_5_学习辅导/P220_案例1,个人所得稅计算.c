/*
个人所得税税率表一（综合所得适用）
级数                全月应纳税所得额                税率（%）    速算扣除数
1                  不超过3000元的                    3          0
2               超过3000元至12000元的部分             10        210
3               超过12000元至25000元的部分            20        1410
4               超过25000元至35000元的部分            25        2660
5               超过35000元至55000元的部分            30        4410
6               超过55000元至80000元的部分            35        7160
7               超过80000元的部分                    45        15160

应纳税所得额 = 月度收入 - 5000元(免征额) - 专项扣除(三险一金等) - 专项附加扣除 - 依法确定的其他扣除

应缴纳个人所得税税额 = 应纳税所得额 × 适用税率 - 速算扣除数

*/

/*
    功能
    使用一个结构体表示税率表的每一个级数, 使用该结构体的数组表示整个税率表
    可以将税率表存储到文件中, 以便之后使用
    利用该税率表计算需要缴纳的税金
*/


# include "stdio.h"
# include "stdlib.h"
# include "stdbool.h"
# include "ctype.h"
# include "iso646.h"

# define TABLERATES "./个人所得税率表(综合所得适用).dat"
# define LEVEL 7
# define EXEMPT 5000


// 用来表达每级的税率
struct _TaxList {
    int stage;   // 级数
    float fore_stage;   // 范围最小值
    float rear_stage;   // 范围最大值
    float rate;   // 税率
    float deduct;   // 速算扣除数
};


typedef struct _TaxList TaxList;


// 初始化个税表, 将在内存中的个稅表返回
TaxList * init_table_rates(){
    FILE * fp = NULL;
    TaxList * tax_table = (TaxList *)calloc(LEVEL, sizeof(TaxList));   // 开辟用来保存税率表的数组, 这种形式可以从函数中返回

    // 如果没能开启文件, 那就新建
    if ( (fp= fopen(TABLERATES, "rb"))==NULL ){
        puts("没有初始化个人所得税率表. 是否进行初始化 y/n.");
        char flag = '\0';
        scanf("%c", &flag);
        if (tolower(flag) != 'y') {
            puts("程序将退出.");
            exit(0);
        }

        if ( (fp=fopen(TABLERATES, "wb")) == NULL ){
            perror("重新创建文件失败.");
            exit(1);
        }
        
        printf("将会容纳级数: %d", LEVEL);
        for (int i=0; i<LEVEL; i++){
            tax_table[i].stage = i;
            printf("\n当前级数 %d\n", i+1);
            if (i != 0){
                printf("输入区间最小值: "); scanf("%f", &tax_table[i].fore_stage);
            } else {
                puts("第1级最小区间自动设置 0.0");
                tax_table[i].fore_stage = .0;
            }
            if (i != 6){
                printf("输入区间最大值: "); scanf("%f", &tax_table[i].rear_stage);
            } else {
                printf("第7级最大区间自动设置 %e\n", __FLT_MAX__);
                tax_table[i].rear_stage = __FLT_MAX__;
            }
            printf("输入该区间税率(.00): "); scanf("%f", &tax_table[i].rate);
            printf("输入该区间扣除数: "); scanf("%f", &tax_table[i].deduct);
            fwrite(&tax_table[i], sizeof(TaxList), 1, fp);
        }
        fclose(fp);
        puts("输入完毕, 保存成功.");
    // 成功开启文件后, 将数据读入数组, 并检验是否完整.
    } else {
        size_t size = 0;
        size = fread(tax_table, sizeof(TaxList), LEVEL, fp);
        if (size < LEVEL){
            perror("数据文件数据文件损坏, 请删除后重新输入.");
            exit(1);
        }
    }
    return tax_table;
}


// 计算稅金, salary: 月收入, tax_table: 内存中的个稅表
bool calculate_tax(float salary, TaxList tax_table[LEVEL]){
    char * format = "需纳税金额: %.2f\n";
    float taxable_income = salary - EXEMPT;   // 会被征税的部分
    
    // 如果需要征税的部分小于0, 那就是不交稅
    if (taxable_income<=0){
        printf(format, 0.0);
        return true;
    }

    // 按级来计算需要征税部分要缴纳的税金
    float result = 0.0;
    for (int i=0; i<LEVEL; i++){
        if (tax_table[i].fore_stage<=taxable_income and taxable_income<=tax_table[i].rear_stage){
            result += taxable_income * tax_table[i].rate - tax_table[i].deduct;
            printf(format, result);
            return true;
        }
    }

    return false;
}


int main(int args, char argv[]){

    TaxList *tax_table = (TaxList *)calloc(LEVEL, sizeof(TaxList));
    tax_table = init_table_rates();

    float salary = .0;

// 循环, 输入小于0的数退出
loop_point:

    printf("输入月工资: "); scanf("%f", &salary);
    if (salary < 0) {
        free(tax_table);
        exit(0);
    }
    calculate_tax(salary, tax_table);

goto loop_point;

    return 0;
}