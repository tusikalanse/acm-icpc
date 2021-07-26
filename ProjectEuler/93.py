'''
Author: tusikalanse
Date: 2021-07-23 15:06:55
LastEditTime: 2021-07-23 15:44:19
LastEditors: tusikalanse
Description: 
'''

def next_permutation(a):
    for i in reversed(range(len(a) - 1)):
        if a[i] < a[i + 1]:
            break
    else:
        return False

    j = next(j for j in reversed(range(i + 1, len(a))) if a[i] < a[j])
    a[i], a[j] = a[j], a[i]
    a[i + 1:] = reversed(a[i + 1:])
    return True

def op(a, o, b):
    if o == 1: return a + b
    if o == 2: return a - b
    if o == 3: return a * b
    if b == 0: return 100000000000
    if o == 4: return a / b

cnt, ans = 0, 0

for a in range(1, 10):
    for b in range(a + 1, 10):
        for c in range(b + 1, 10):
            for d in range(c + 1, 10):
                vis = dict()
                s = [a, b, c, d]
                while True:
                    for op1 in range(1, 5):
                        for op2 in range(1, 5):
                            for op3 in range(1, 5):
                                vis[op(op(op(s[0], op1, s[1]), op2, s[2]), op3, s[3])] = 1
                                vis[op(op(s[0], op1, op(s[1], op2, s[2])), op3, s[3])] = 1
                                vis[op(op(s[0], op1, s[1]), op2, op(s[2], op3, s[3]))] = 1
                                vis[op(s[0], op1, op(s[1], op2, op(s[2], op3, s[3])))] = 1
                                vis[op(s[0], op1, op(op(s[1], op2, s[2]), op3, s[3]))] = 1
                    if not next_permutation(s):
                        break
                
                ccnt = 1
                while True:
                    if ccnt not in vis:
                        break
                    ccnt += 1
                if ccnt > cnt:
                    cnt = ccnt
                    ans = str(a) + str(b) + str(c) + str(d)

print(cnt, ans)
