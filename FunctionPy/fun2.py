def div(c):
    a = 0
    for i in range(1,c+1):
        if c % i == 0:
            a = a + 1
    return a

for i in range(100,1000):
    if div(i) == 2: print(i)