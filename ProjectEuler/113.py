'''
Author: tusikalanse
Date: 2021-08-17 20:37:19
LastEditTime: 2021-08-17 20:48:28
LastEditors: tusikalanse
Description: Partition Combine Number
'''
from math import factorial

def C(n, m):
    if n < m or m < 0 or n < 0: return 0
    return factorial(n) // factorial(m) // factorial(n - m)

n = 100
ans = -1 # except zero

for i in range(1, n + 1):
    ans += C(i - 1 + 10, 9)

ans += C(n - 1 + 10, 9)
ans -= 10 * n

print(ans)