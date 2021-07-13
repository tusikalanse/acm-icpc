'''
Author: tusikalanse
Date: 2021-07-13 20:50:20
LastEditTime: 2021-07-13 21:26:19
LastEditors: tusikalanse
Description: 
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
    for i in range(1, 2 * len(lis)):
        k = gao(i, lis)
        if k[0] * k[0] - n * k[1] * k[1] == 1:
            return k
    exit(0)
    return [0, 0]

mx, id = 0, -1

for i in range(2, 1001):
    if sqrt(i) == int(sqrt(i)):
        continue
    l = getperiod(i)
    t = getminx(i, l)
    if t[0] > mx:
        mx = t[0]
        id = i

print(id)