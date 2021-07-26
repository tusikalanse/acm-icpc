'''
Author: tusikalanse
Date: 2021-06-30 22:23:08
LastEditTime: 2021-06-30 22:31:10
LastEditors: tusikalanse
Description: 
FilePath: /ProjectEuler/19.py
'''

def isleap(x: int) -> bool:
    return x % 4 == 0 if x % 100 != 0 else x % 400 == 0

day = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

count = 0
first = 1
for year in range(1900, 2001):
    for month in range(12):
        if year != 1900:
            count += first == 0
        first += day[month]
        if month == 1:
            first += isleap(year)
        first %= 7

print(count)    