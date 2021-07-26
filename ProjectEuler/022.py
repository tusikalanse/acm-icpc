'''
Author: tusikalanse
Date: 2021-07-01 20:00:45
LastEditTime: 2021-07-01 20:12:25
LastEditors: tusikalanse
Description: 
FilePath: /ProjectEuler/22.py
'''
namelist = input().split(',')
namelist = sorted(namelist)
ans = 0
for i in range(len(namelist)):
    name = namelist[i].strip('"')
    sum = 0
    for x in name:
        sum += ord(x) - ord('A') + 1
    ans += sum * (i + 1)
print(ans)