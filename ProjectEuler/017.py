'''
Author: tusikalanse
Date: 2021-06-30 22:12:01
LastEditTime: 2021-06-30 22:15:01
LastEditors: tusikalanse
Description: 
FilePath: /ProjectEuler/17.py
'''

a = 36 + 70 + 36 * 8 + 10 * (6 + 6 + 5 + 5 + 5 + 7 + 6 + 6)
#36: 1-9
#70: 10-19
#36*8 : 20-99 last digit
#10*.. : 20-99 first digit
print(a)
b = a + 7 * 900 + 11 + 3 * 891 + 854 * 9 + 36 * 100
print(b)