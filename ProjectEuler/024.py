'''
Author: tusikalanse
Date: 2021-07-01 20:14:30
LastEditTime: 2021-07-01 20:18:06
LastEditors: tusikalanse
Description: 
FilePath: /ProjectEuler/24.py
'''
from math import factorial
n = 10

ans = ""

vis = [str(i) for i in range(10)]

count = int(input()) - 1

for digit in range(n):
    d = factorial(n - digit - 1)
    x = count // d
    ans += vis[x]
    vis.pop(x)
    count -= d * x

print(ans)
