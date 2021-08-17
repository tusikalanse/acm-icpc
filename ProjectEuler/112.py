'''
Author: tusikalanse
Date: 2021-08-17 17:34:03
LastEditTime: 2021-08-17 20:48:49
LastEditors: tusikalanse
Description: Bouncy numbers
'''

def is_increasing(x):
    s = str(x)
    for i in range(len(s) - 1):
        if s[i] > s[i + 1]:
            return False
    return True


def is_decreasing(x):
    s = str(x)
    for i in range(len(s) - 1):
        if s[i] < s[i + 1]:
            return False
    return True


rate = 100

num, cnt = 0, 0

while True:
    num += 1
    cnt += is_increasing(num) or is_decreasing(num)
    if cnt * rate == num:
        break

print(num, cnt)