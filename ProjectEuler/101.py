'''
Author: tusikalanse
Date: 2021-07-30 11:19:09
LastEditTime: 2021-07-30 11:19:16
LastEditors: tusikalanse
Description: largrange
'''

def largrange(k, n, f):
    ans = 0
    for i in range(n + 1):
        prod = 1
        for j in range(n + 1):
            if i == j: continue
            prod *= k - f[j][0]
            prod /= f[i][0] - f[j][0]
        ans += f[i][1] * prod
    return int(ans)

f = [1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1]

v = []
for i in range(1, 12):
    res = 0
    for j in range(11):
        res += f[j] * (i ** j)
    v.append([i, res])

seq = []

for i in range(11):
    s = []
    for j in range(1, 12):
        s.append(largrange(j, i, v))
    seq.append(s)


ans = 0
for i in range(11):
    for j in range(11):
        if seq[i][j] != seq[-1][j]:
            ans += seq[i][j]
            break

print(ans)