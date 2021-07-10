'''
Author: tusikalanse
Date: 2021-07-10 18:07:33
LastEditTime: 2021-07-10 18:10:07
LastEditors: tusikalanse
Description: 
'''

cnt = 0

def gao(i: int) -> int:
    for _ in range(50):
        i = i + int(str(i)[::-1])
        if str(i) == str(i)[::-1]:
            return 0
    return 1

for i in range(10000):
    cnt += gao(i)

print(cnt)