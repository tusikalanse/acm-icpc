'''
Author: tusikalanse
Date: 2021-08-30 09:30:32
LastEditTime: 2021-08-30 09:30:40
LastEditors: tusikalanse
Description: 
'''
def reversible_numbers(n):
    if n % 2 == 0: 
        return 20 * 30 ** (n // 2 - 1)
    if n % 4 == 1:
        return 0
    if n % 4 == 3:
        return 5 * 20 * (25 * 20) ** ((n - 3) // 4)

print(sum([reversible_numbers(i) for i in range(2, 10)]))