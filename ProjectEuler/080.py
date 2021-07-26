'''
Author: tusikalanse
Date: 2021-07-19 12:33:42
LastEditTime: 2021-07-19 12:43:21
LastEditors: tusikalanse
Description: 
'''


from math import sqrt

def is_square(x):
    d = int(sqrt(x + 0.5))
    return d * d == x

def get_digit(x, y):
    for i in range(9, 0, -1):
        if i * (i + x * 10) <= y:
            return i
    return 0

def gao(x):
    ans = 0
    divider = 0
    reminder = x
    for i in range(100):
        j = get_digit(divider, reminder)
        reminder -= j * (j + divider * 10)
        ans += j
        divider = divider * 10 + 2 * j
        reminder *= 100
    return ans

total = 0

for i in range(100):
    if is_square(i):
        continue
    total += gao(i)

print(total)