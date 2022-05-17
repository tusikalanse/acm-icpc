'''
Author: tusikalanse
Date: 2021-12-27 20:22:19
LastEditTime: 2021-12-29 11:29:15
LastEditors: tusikalanse
Description: pell equation -1
'''
from math import sqrt

# g(x) = (3 * x * x + x) / (1 - x - x * x)


def getperiod(x):
    m, d = 0, 1
    a0 = int(sqrt(x))
    a = a0
    p = [0, a0]
    while a0 * 2 != a:
        m = a * d - m
        d = (x - m * m) / d
        a = (int)((m + sqrt(x)) / d)
        p.append(a)
    return p

def gao(n, lis):
    if n == 1:
        return [lis[1], 0]
    numerator, denominator = lis[(n - 2) % (len(lis) - 2) + 2], 1
    for i in range(n - 1, 1, -1):
        numerator, denominator = denominator, numerator
        numerator += denominator * lis[(i - 2) % (len(lis) - 2) + 2]
    numerator, denominator = denominator, numerator
    numerator += denominator * lis[1]
    return [numerator, denominator]

def getminx(n, lis, des):
    for i in range(2, 2 * len(lis)):
        k = gao(i, lis)
        if k[0] * k[0] - n * k[1] * k[1] == des:
            return k
    exit(0)
    return [0, 0]


l = getperiod(5)
t = getminx(5, l, -1)
x0, y0 = getminx(5, l, 44)
x, y = t
print(l, t)
exit(0)
ans = 0
limit = int(1e12)
print(l, t)

cnt = 0
ans = 0

while True:
    # print("x, y, cnt = ", x, y, cnt)
    if (x % 5 == 2 or x % 5 == 3) and x * x - 5 * y * y == -1:
        if x % 5 == 2:
            print(x, (x - 2) // 5, y)
        else:
            print(x, (x + 2) // 5, y)
        cnt += 1
        ans += y
        if cnt == 12: 
            break
    x, y = x0 * x + 5 * y0 * y, x0 * y + x * y0

print(ans)