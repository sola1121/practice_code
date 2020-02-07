import time


x = 25
epsilon = 0.001
step = epsilon ** 2   # 步子, 用以增加答案的
num_guesses = 0   # 用于记录运算了多少次
ans =  0.0  # float()

# 穷举, 在有效集合内找出最优解

start_time = time.clock()

while abs(ans**2-x)>=epsilon and ans<=x:   # 接近的结果, 结果平方与原数比要差距大于epsilon, 并且结果要小于原数
    ans += step   # 通过累加获得结果
    num_guesses += 1

print("使用穷举法猜了的次数:", num_guesses)

if abs(ans**2-x) >= epsilon:   # 是否偏离精确值
    print("开平方失败%d" %x)
else:
    print("对%d开平方成功, 结果是%d" %(x, ans))

print("穷举CPU用时:", time.clock()-start_time, "\n\n\n")

# 二分法
num_guesses2 = 0   # 用于记录计算了多少次
low = 0.0
high = max(1.0, x)
ans = (low+high)/2

start_time = time.clock()

while abs(ans**2-x)>=epsilon:  # 判断与原值的差距, 要取到精确值, 不能超过epsilon
    print("当前low=", low, "  high=", high, "  ans=", ans)
    num_guesses2 += 1
    if ans**2 < x:   # 比较答案和原数的高低差距
        low = ans
    else:
        high = ans
    ans = (low+high)/2   # 每一次取两头的中间作为答案, 在循环带入比较

print("使用二分法猜了的次数:", num_guesses2)
print("对%d开平方成功, 结果是%d" %(x, ans))
print("二分CPU用时:", time.clock()-start_time)
