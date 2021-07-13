'''
Author: tusikalanse
Date: 2021-07-13 20:13:20
LastEditTime: 2021-07-13 20:30:51
LastEditors: tusikalanse
Description: 
'''

lis = [0, 2]

for i in range(1, 34):
    lis.extend([1, 2 * i, 1])

def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

def gao(n):
    numerator, denominator = lis[n], 1
    for i in range(n - 1, 0, -1):
        numerator, denominator = denominator, numerator
        numerator += denominator * lis[i]
        g = gcd(numerator, denominator)
        numerator //= g
        denominator //= g
    return [numerator, denominator]

print(gao(100))
e = gao(100)[0]

s = sum(map(int, str(e)))

print(s)