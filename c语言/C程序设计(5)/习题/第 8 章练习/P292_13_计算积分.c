# include "stdio.h"
# include "math.h"

/*
    https://zh.wikipedia.org/zh-hans/%E7%9F%A9%E5%BD%A2%E6%B3%95#:~:text=%E5%BE%AE%E7%A7%AF%E5%88%86%E4%B8%AD%EF%BC%8C%E7%9F%A9%E5%BD%A2%E6%B3%95,%E7%94%B1%E5%87%BD%E6%95%B0%E5%80%BC%E6%9D%A5%E5%86%B3%E5%AE%9A%E3%80%82&text=%E7%9A%84%E9%95%BF%E5%BA%A6%E4%B8%BA-,%E3%80%82,%E7%AD%89%E4%BA%8E%E5%AE%9A%E7%A7%AF%E5%88%86%E7%9A%84%E8%BF%91%E4%BC%BC%E5%80%BC%E3%80%82
    矩形法计算积分的值: ∫[0,1]sinxdx, ∫[0,1]cosxdx, ∫[0,1]pow(e,x)dx
    x∈[a, b],n∈Z+, 面积S = Σ[1,n]f(x)Δxi, Δxi = (b-a)/n, 这里的x = a + Δxi * i
*/

void caculate_definite_intergral(double (*func)(double), double l_limit, double u_limit, int n){
    double result = 0.0, delta_x = (u_limit - l_limit) / n;
    for (int count = 1;count<=n; count++){
        result += func(l_limit + count*delta_x) * delta_x;
    }
    printf("在区间[%.2lf,%.2lf],精度n=%d, 当前计算结果: %lf \n", l_limit, u_limit, n, result);
}


int main(){
    caculate_definite_intergral(sin, 0, 1, 100);
    caculate_definite_intergral(cos, 0, 1, 100);
    caculate_definite_intergral(exp, 0, 1, 100);

    return 0;
}
