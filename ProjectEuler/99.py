'''
Author: tusikalanse
Date: 2021-07-23 11:16:48
LastEditTime: 2021-07-23 11:26:28
LastEditors: tusikalanse
Description: 
'''

from math import log

f = open("99.in", "r")

nums = f.readlines()

for i in range(len(nums)):
    nums[i] = list(map(int, nums[i].strip().split(',')))

mx, id = 0, -1

for i in range(len(nums)):
    a, b = nums[i]
    if b * log(a) > mx:
        mx = b * log(a)
        id = i

print(nums[id])
print(id + 1)