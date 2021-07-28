'''
Author: tusikalanse
Date: 2021-07-28 17:14:57
LastEditTime: 2021-07-28 17:14:58
LastEditors: tusikalanse
Description: pell equation -1
'''


from math import sqrt

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

def getminx(n, lis):
    for i in range(2, 2 * len(lis)):
        k = gao(i, lis)
        if k[0] * k[0] - n * k[1] * k[1] == -1:
            return k
    exit(0)
    return [0, 0]


l = getperiod(2)
t = getminx(2, l)
x0, y0 = 3, 2
x, y = t
ans = 0
limit = int(1e12)
print(l, t)

while True:
    print("x, y = ", x, y)
    if x % 2 == 1 and y % 2 == 1 and x * x - 2 * y * y == -1:
        a, b = (x + 1) // 2, (y + 1) // 2
        print(a, b)
        if a > limit:
            print(a, b)
            break
    x, y = x0 * x + 2 * y0 * y, x0 * y + x * y0