#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import copy

length, count = 10, 0
num_box = list()

while count < length:
    try:
        num_box.append(int(input("输入第{count}个数字: ".format(count=count+1))))
    except Exception as e:
        print(e)
        break
    count += 1

result_num_box = copy.deepcopy(num_box)
for elment in num_box:
    if elment % 2 == 0:
        print("移除偶数: ", elment)
        result_num_box.remove(elment)

print("处理后的奇数列表: ", result_num_box)
print("求出最大奇数: ", max(result_num_box))
    