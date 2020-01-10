count = 0
num = input("Plz input a number: ")

while num == f"{num}":
    print("不论怎样都会输出的一行字", num, sep="\n")
    count += 1
    if count == 3:
        break
else:
    print(f"{num}")