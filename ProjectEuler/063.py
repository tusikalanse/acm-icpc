'''
Author: tusikalanse
Date: 2021-07-12 17:41:34
LastEditTime: 2021-07-12 17:44:26
LastEditors: tusikalanse
Description: 
'''

ans = 0

for a in range(1, 10):
    for n in range(1, 10000000):
        l = len(str(a ** n))
        if l < n:
            break
        ans += l == n

print(ans)
