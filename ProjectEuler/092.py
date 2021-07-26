'''
Author: tusikalanse
Date: 2021-07-22 17:13:49
LastEditTime: 2021-07-22 17:27:22
LastEditors: tusikalanse
Description: 
'''

from math import factorial

cnt = dict()

def gao(x: int)-> int:
    return sum(map(lambda x: int(x) * int(x), str(x)))

for i in range(1, 10000000):
    if i in cnt: continue
    length = 0
    l = dict()
    x = i
    while x not in l and x not in cnt:
        l[x] = length
        length += 1
        x = gao(x)
    if x in cnt: 
        x = cnt[x]
    for d in l:
        cnt[d] = x

ans = 0
for d in cnt:
    if cnt[d] == 4:
        ans += 1

print(ans)
