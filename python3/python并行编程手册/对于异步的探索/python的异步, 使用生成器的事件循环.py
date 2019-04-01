def generator_1():
    total = 0
    while True:
        x = yield 
        print('加',x)
        if not x:
            break
        total += x
    return total


def generator_2(): # 委托生成器
    while True:
        total = yield from generator_1() # 子生成器
        print('加和总数是:',total)


def main(): # 调用方
    # g1 = generator_1()
    # g1.send(None)
    # g1.send(2)
    # g1.send(3)
    # g1.send(None)
    g2 = generator_2()
    g2.send(None)
    g2.send(2)
    g2.send(3)
    g2.send(None)
    g2.send(6)
    g2.send(None)
    

main()
