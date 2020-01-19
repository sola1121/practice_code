# 寻找x, 满足x**2-24在epsilon和0之间, 类同于x**2-24=0 解x
num_count = 0
epsilon = .01
k = 24

guess = k/2.0   # 起始值就从原数的一半开

while abs(guess*guess-k) >= epsilon:   # 判断是否足够接近原数了
    guess = guess-(((guess**2)-k)/(2*guess))   # 如果存在一个值guess是多项式p的根的近似值, 那么guess-p(guess)/p'(guess)就是一个更好的近似值
    num_count += 1

print("开24的平方:", guess)
print("进行了%d次计算"%num_count)