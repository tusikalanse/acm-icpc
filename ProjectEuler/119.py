'''
Author: tusikalanse
Date: 2021-08-19 19:10:40
LastEditTime: 2021-08-19 19:15:41
LastEditors: tusikalanse
Description: 
'''


n = 30

x = int(10 ** n)

ans = []

def getsum(x):
    return sum(list(map(int, str(x))))

for i in range(2, 9 * n + 1):
    v = i
    while v <= x:
        if v >= 10 and getsum(v) == i:
            ans.append(v)
        v *= i

ans = sorted(ans)

print(ans[9], ans[29])