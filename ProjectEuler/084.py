'''
Author: tusikalanse
Date: 2021-07-19 19:40:17
LastEditTime: 2021-07-19 20:12:43
LastEditors: tusikalanse
Description: 
'''

import random

rounds = 1000000

cnt = [[0, i] for i in range(40)]

now = 0
dice = [0, 0]

CC = [i for i in range(16)]
random.shuffle(CC)
CH = [i for i in range(16)]
random.shuffle(CH)
print(CC, CH)

for i in range(rounds):
    x = random.randint(1, 4)
    y = random.randint(1, 4)
    d = x + y
    now += d
    now %= 40
    if dice[0] == dice[1] and dice[0] == d:
        now = 10
    elif now == 2 or now == 17 or now == 33:
        p = CC[0]
        CC = CC[1:] + CC[:1]
        if p == 1: now = 0
        elif p == 2: now = 10
    elif now == 7 or now == 22 or now == 36:
        p = CH[0]
        CH = CH[1:] + CH[:1]
        if p == 1: now = 0
        elif p == 2: now = 10
        elif p == 3: now = 11
        elif p == 4: now = 24
        elif p == 5: now = 39
        elif p == 6: now = 5
        elif p == 7 or p == 8: now = (now + 5) % 40 // 10 * 10 + 5
        elif p == 9 or p == 10:
            if now >= 12 and now < 28:
                now = 28
            else:
                now = 12
    elif now == 30:
        now = 10
    cnt[now][0] += 1

cnt.sort(key=lambda x: -x[0])

print(cnt)
print(str(cnt[0][1]) + str(cnt[1][1]) + str(cnt[2][1]))