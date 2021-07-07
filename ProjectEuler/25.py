'''
Author: tusikalanse
Date: 2021-07-01 20:20:08
LastEditTime: 2021-07-01 20:22:21
LastEditors: tusikalanse
Description: 
FilePath: /ProjectEuler/25.py
'''

F = [0 for i in range(10000)]
F[0] = 1
F[1] = 1

for i in range(2, len(F)):
    F[i] = F[i - 1] + F[i - 2]
    if len(str(F[i])) >= 1000:
        print(i + 1)
        break

