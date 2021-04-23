def simple (x):
    a = 0
    for i in range(1,x + 1):
        if x % i == 0:
             a = a + 1
    if a == 2:
        return True
    else:
        return False

ans = 0
for i in range(10,100):
    if simple(i): ans = ans + i
print(ans)