/*
    1. 输入或读取学生的学号,平时成绩,期末成绩
    2. 计算平时成绩的及格率, 平均分, 标准差; 期末成绩的及格率, 平均分, 标准差; 总评的及格率, 平均分, 标准差
        总评 = 平时成绩*20% + 考试成绩*80%
        并统计出各个成绩的最高分, 最低分
    3. 做图, 人数-分数段分布图
*/


# include "stdio.h"
# include "stdlib.h"
# include "math.h"
# include "iso646.h"

# define SCOREFILE "./students_score.csv"
# define PASSSCORE 60

static int stu_num = 0;   // 全局变量用来记录学生人数


struct Student {
    unsigned int id;
    float score[3];   // score[0]平时成绩, score[1]期末成绩, score[2]总评成绩
};


typedef struct Student Student;


// 子函数, 通过socre0平时成绩, score1期末成绩, 来计算总评成绩
float get_evaluated_score(float socre0, float socre1){
    float evaluated = .0;
    evaluated += socre0 * .2 + socre1 * .8;
    return evaluated;
}


// 子函数, 从特定的csv中读取内容, 将其存在Student 数组中返回
Student * read_csv(FILE * fp){
    // 获取数据的个数, 以行算, 注意最后一个EOF也算作一行
    int count = 0;
    char temp[1024] = {};
    while (!feof(fp)){
        count += 1;
        fgets(temp, sizeof(Student), fp);
    }
    rewind(fp);
    printf("共获得 %d 个数据\n", count);

    stu_num = count;
    Student * stus = (Student *)calloc(stu_num, sizeof(Student));   // 用来存储数据的数组

    unsigned int i = 0, id = 0;
    float score0 = .0, score1 = .0;
    while (!feof(fp) and i<stu_num){
        fscanf(fp, "%u,%f,%f\n", &id, &score0, &score1);
        stus[i].id = id;
        stus[i].score[0] = score0;
        stus[i].score[1] = score1;
        stus[i].score[2] = get_evaluated_score(score0, score1);
        i += 1;
    }

    return stus;
}


// 从键盘输入或者从文件中或取学生的成绩, 将其存在Student 数组中返回
Student * input_student(){
    int flag = 0;
    puts("1. 将从终端输入中读取.");
    printf("2. 将从运行目录%s文件中读取.\n", SCOREFILE);
    puts("3. 退出.");
    printf("选取读取模式:");
    scanf("%d", &flag);
    while (flag!=1 and flag!=2 and flag!=3){
        printf("模式未识别, 请重新输入:");
        scanf("%d", &flag);
    }

    switch (flag){
        // 从stdin 中获取学生成绩
        case 1:
            printf("请输入需处理学生人数:");
            scanf("%d", &stu_num);
            Student * stus = (Student *) calloc(stu_num, sizeof(Student));
            for (int i=0; i<stu_num; i++){
                printf("\n学生学号: "); scanf("%u", &(stus[i].id));
                printf("平时成绩: "); scanf("%f", stus[i].score+0);
                printf("期末成绩: "); scanf("%f", stus[i].score+1);
                stus[i].score[2] = get_evaluated_score(stus[i].score[0], stus[i].score[1]);
            }
            return stus;
        // 从指定的文件还总读取学生成绩
        case 2:
            puts("正在从文件中读取...");
            FILE * fp = NULL;
            if ( (fp=fopen(SCOREFILE, "r"))==NULL ){
                puts("文件打开不成功.");
                exit(0);
            }
            return read_csv(fp);
        case 3:
            puts("程序退出.");
            exit(0);
        default:
            perror("程序错误退出.");
            exit(1);
    }
    return NULL;
}


// 从Student 数组中输出内容
void output_stus(Student stus[], int num){
    puts("学生学号     平时成绩    期末成绩    总评成绩");
    for (int i=0; i<num; i++)
        printf("%-10u%10.2f%10.2f%10.2f\n", stus[i].id, stus[i].score[0], stus[i].score[1], stus[i].score[2]);
    putchar('\n');
}


// 子函数, 计算标准差
float standard_deviation(float *scores, int num){
    float avg_score = .0, powf_sum = .0;
    for (int i=0; i<num; i++)
        avg_score += *(scores+i);
    avg_score /= num;

    for (int i=0; i<num; i++)
        powf_sum += powf(*(scores+i)-avg_score, 2.0);

    return sqrtf(powf_sum/num);
}


// 从Student 数组中分析数据
void analysis(Student stus[], int num){
    // 及格率
    unsigned int unpass_count_0 = 0, unpass_count_1 = 0, unpass_count_2 = 0;
    // 最高,最低分,各期总分
    float sum_score_0 = .0, sum_score_1 = .0, sum_socre_2 = .0,
          max_score_0 = .0, max_score_1 = .0, max_score_2 = .0,
          min_score_0 = stus[0].score[0], min_score_1 = stus[0].score[1], min_score_2 = stus[0].score[2];
    // 分别提取各期的数据, 用来单独计算标准差
    float  *score0 = (float *) calloc(num, sizeof(float)),
           *score1 = (float *) calloc(num, sizeof(float)),
           *score2 = (float *) calloc(num, sizeof(float));

    for (int i=0; i<num; i++){
        if (stus[i].score[0] < PASSSCORE) unpass_count_0 += 1;
        if (stus[i].score[1] < PASSSCORE) unpass_count_1 += 1;
        if (stus[i].score[2] < PASSSCORE) unpass_count_2 += 1;
        if (max_score_0 < stus[i].score[0]) max_score_0 = stus[i].score[0];
        if (max_score_1 < stus[i].score[1]) max_score_1 = stus[i].score[1];
        if (max_score_2 < stus[i].score[2]) max_score_2 = stus[i].score[2];
        if (min_score_0 > stus[i].score[0]) min_score_0 = stus[i].score[0];
        if (min_score_1 > stus[i].score[1]) min_score_1 = stus[i].score[1];
        if (min_score_2 > stus[i].score[2]) min_score_2 = stus[i].score[2];
        sum_score_0 += stus[i].score[0];
        sum_score_1 += stus[i].score[1];
        sum_socre_2 += stus[i].score[2];
        score0[i] = stus[i].score[0];
        score1[i] = stus[i].score[1];
        score2[i] = stus[i].score[2];
    }
    // 输出及格率
    printf("平时成绩及格率: %4.1f%%, ", (1.0 - (float)unpass_count_0/num)*100.0);
    printf("期末成绩及格率: %4.1f%%, ", (1.0 - (float)unpass_count_1/num)*100.0);
    printf("总评成绩及格率: %4.1f%%\n", (1.0 - (float)unpass_count_2/num)*100.0);
    // 输出最大,最小值
    printf("平时成绩最大值: %5.2f, 期末成绩最大值: %5.2f, 总评成绩最大值: %5.2f\n", max_score_0, max_score_1, max_score_2);
    printf("平时成绩最小值: %5.2f, 期末成绩最小值: %5.2f, 总评成绩最小值: %5.2f\n", min_score_0, min_score_1, min_score_2);
    // 平均值
    printf("平时成绩平均值: %5.2f, 期末成绩平均值: %5.2f, 总评成绩平均值: %5.2f\n", sum_score_0/num, sum_score_1/num, sum_socre_2/num);
    // 标准差
    printf("平时成绩标准差: %5.2f, ", standard_deviation(score0, num));
    printf("期末成绩标准差: %5.2f, ", standard_deviation(score1, num));
    printf("总评成绩标准差: %5.2f\n", standard_deviation(score2, num));

    free(score0);
    free(score1);
    free(score2);
}


// 打印成绩分步
void plot_histogram(int X[], int Y[]){
    // TODO: 没有完成绘图功能

}


/*
    处理的数据样式
    x轴, 表示在这个区间段里的
    [0, 10, 20, 20, 40, 50, 60, 70, 80, 90]

    y轴, 表示对应区间段中出现数据的个数
    [0,  1,  2,  2,  5,  8, 16,  9,  7,  5]
*/


int array_min(int array[], int len){
    int result = array[0];
    for (int i=0; i<len; i++)
        if (result>array[i]) result = array[i];
    return result;
}


int array_max(int array[], int len){
    int result = array[0];
    for (int i=0; i<len; i++)
        if (result<array[i]) result = array[i];
    return result;
}

// TODO: 还在整的绘图功能, 就是没有那效果
void plot_test(){
    int width = 10, height = 10;
    // NOTE: 动态的建立数组
    int* *screen = (int**) malloc (sizeof(int*) * height);
    for (int i=0; i<height; i++){
        screen[i] = (int*) malloc(sizeof(int)*width);
    }
    // 生成screen内容
    int count = 0;
    for (int h=height-1; h>=0; h--){
        for (int w=0; w<width; w++){
            screen[h][w] = count*10;
        }
        count ++;
    }
    // 打印screen内容
    for (int m=0; m<height; m++){
        for (int n=0; n<width; n++)
            printf("%4d", screen[m][n]);
        putchar('\n');
    }

    // 测试用数据
    int x_array[10] = {0, 10, 20, 20, 40, 50, 60, 70, 80, 90},
        y_array[10] = {0,  1,  2,  2,  5,  8, 16,  9,  7,  5};

    float k = .0;
    int min = array_min(y_array, 10),
        max = array_max(y_array, 10);
    
    k = (100-0)/(max-min);   // 系数, 用以将数据归一化到[0, 100]区间

    puts("用以测试的数据:");
    for (int i=0; i<10; i++){
        y_array[i] = min + k * (y_array[i]-min);   // 将数据归一化到[0, 100]区间
        printf("%-4d", y_array[i]);
    }
    putchar('\n');

    puts("Y");
    for (int h=height-1; h>=0; h--){
        for (int w=0; w<width; w++){
            if (w==0) printf("|");
            if (screen[h][w]<=y_array[w]){
                    printf("*");
            } else {
                printf(" ");
            }
            
        }
        putchar('\n');
    }
    putchar('\n');
}


int main(int args, char *argv[]){

    // Student * stus = input_student();

    // output_stus(stus, stu_num);

    // analysis(stus, stu_num);

    plot_test();

    // free(stus);

    return 0;
}