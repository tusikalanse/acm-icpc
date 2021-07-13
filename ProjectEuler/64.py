'''
Author: tusikalanse
Date: 2021-07-13 19:48:40
LastEditTime: 2021-07-13 20:12:30
LastEditors: tusikalanse
Description: 
'''

from math import sqrt

ans = 0
#See On continued fractions of the square root of prime numbers.pdf 3.3

def getperiodlength(x):
    m, d = 0, 1
    a0 = int(sqrt(x))
    length = 0
    a = a0
    while a0 * 2 != a:
        m = a * d - m
        d = (x - m * m) / d
        a = (int)((m + sqrt(x)) / d)
        length += 1
    return length


for i in range(2, 10001):
    if sqrt(i) == int(sqrt(i)):
        continue
    if getperiodlength(i) % 2 == 1:
        ans += 1

print(ans)