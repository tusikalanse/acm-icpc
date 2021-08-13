'''
Author: tusikalanse
Date: 2021-08-12 21:06:22
LastEditTime: 2021-08-12 21:06:22
LastEditors: tusikalanse
Description: 
'''
def is_pandigital(x):
    cnt = 9
    vis = [0] * 10
    vis[0] = 1
    while cnt:
        d = x % 10
        if vis[d]:
            return False
        vis[d] = 1
        cnt -= 1
        x //= 10
    return True

mod = int(1e9)

pre = [1, 1]
now = [1, 1]
nxt = [0, 0]
for i in range(3, 10000000):
    nxt[0] = pre[0] + now[0]
    nxt[1] = pre[1] + now[1]
    nxt[0] %= mod
    if is_pandigital(int(str(nxt[1])[::-1])) and is_pandigital(nxt[0]):
        print(i)
        break
    pre[0] = now[0]
    now[0] = nxt[0]
    pre[1] = now[1]
    now[1] = nxt[1]
    if now[1] > 1e20:
        now[1] //= 10
        pre[1] //= 10