'''
Author: tusikalanse
Date: 2022-04-02 14:26:42
LastEditTime: 2022-04-02 14:31:05
LastEditors: tusikalanse
Description: 
'''

for case in range(1, 1 + int(input())):
    print("Case #%d: " % case, end='')
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    d = [0, 0, 0, 0]
    for i in range(4):
        d[i] = min(a[i], b[i], c[i])
    if sum(d) < 1000000:
        print("IMPOSSIBLE")
    else:
        rem = 1000000
        for x in range(len(d)):
            if d[x] > rem:
                d[x] = rem
            rem -= d[x]
        print(*d, sep=' ')