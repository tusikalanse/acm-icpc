'''
Author: tusikalanse
Date: 2021-07-15 19:22:52
LastEditTime: 2021-07-15 20:06:26
LastEditors: tusikalanse
Description: 
'''

from math import factorial

cnt = dict()

def gao(x: int)-> int:
    return sum(map(factorial, map(int, str(x))))

for i in range(1, 1000000):
    if i in cnt: continue
    length = 0
    l = dict()
    x = i
    while x not in l and length < 62:
        l[x] = length
        length += 1
        x = gao(x)
    if x not in l:
        continue
    for d in l:
        if length - l[d] < length - l[x]: continue
        cnt[d] = length - l[d]
        
ans = 0
for d in cnt:
    if d < 1000000 and cnt[d] == 60:
        ans += 1

print(ans)
