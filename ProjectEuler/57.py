'''
Author: tusikalanse
Date: 2021-07-12 12:40:43
LastEditTime: 2021-07-12 12:43:03
LastEditors: tusikalanse
Description: 
'''
'''
Author: tusikalanse
Date: 2021-07-12 12:40:42
LastEditTime: 2021-07-12 12:40:42
LastEditors: tusikalanse
Description: 
'''
ans = 0

numerator = 1
denominator = 1

for i in range(1000):
    numerator += denominator
    numerator, denominator = denominator, numerator
    numerator += denominator
    # print(numerator, '/', denominator)
    ans += len(str(numerator)) > len(str(denominator))

print(ans)