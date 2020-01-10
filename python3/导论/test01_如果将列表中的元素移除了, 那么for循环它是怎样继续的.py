lst = [1,2,3,4,5,6]

for i in lst:
    print("当前元素: ", i)
    if i == 2:
        lst.remove(i)
    print(lst)

# 会跳过对后一个元素的检查