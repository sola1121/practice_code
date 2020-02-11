import sys

print("递归层数限制:", sys.getrecursionlimit())

def fab(n):
    # 求斐波那契数列 1 1 2 3 5 8 13
    if not (isinstance(n, int) and n >= 0):
        raise ValueError("n must be a positive integer.")
    if n == 1 or n == 0:
        return 1
    else:
        return fab(n-1) + fab(n-2)

for i in range(4, 8):
    print(fab(i))


# 回文
def is_plindrome(s):
    """
    假设s是字符串
    如果s是回文字符串则返回True, 否则返回False
    忽略标点符号,空格和大小写
    """
    def to_char(s):
        s = s.lower()
        letters = str()
        for c in s:
            if c in list(map(chr, list(range(97, 123)))):
                letters = letters + c
        return letters

    def is_pal(s):
        if len(s) <= 1:
            return True
        else:
            return s[0] == s[-1] and is_pal(s[1:-1])   # 从左到右依次, 若果第一个==为False那么就已经结束返回了

    return is_pal(to_char(s))

output = is_plindrome('a')
print(output)
