def count(x):
    a = 0
    while x > 0:
        a = a + x % 10
        x = x // 10
    return a

b = int(input())
i = b + 1
b = count(b)
while b:
    if count(i) == b:
        print(i)
        break
    else: i = i + 1 