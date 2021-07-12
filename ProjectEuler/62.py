'''
Author: tusikalanse
Date: 2021-07-12 17:30:02
LastEditTime: 2021-07-12 17:33:52
LastEditors: tusikalanse
Description: 
'''
cnt = dict()

def gao(x):
    return "".join(sorted(str(x)))

for i in range(10000):
    s = gao(i ** 3)
    if s in cnt:
        cnt[s][0] += 1
        cnt[s][1].append(i ** 3)
        if cnt[s][0] == 5:
            print(cnt[s][1])
            exit(0)
    else:
        cnt[s] = [1, [i ** 3]]
