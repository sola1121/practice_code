int Global = 0;

int power(int n){
    int result = 1;
    for(int i=1; i<=n; i++)
        result *= Global;
    return result;
}