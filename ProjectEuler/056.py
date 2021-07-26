'''
Author: tusikalanse
Date: 2021-07-10 18:12:09
LastEditTime: 2021-07-10 18:12:09
LastEditors: tusikalanse
Description: 
'''
'''
Author: tusikalanse
Date: 2021-07-10 18:12:08
LastEditTime: 2021-07-10 18:12:09
LastEditors: tusikalanse
Description: 
'''
ans = 0

for i in range(1, 100):
    for j in range(100):
        temp = i ** j
        ans = max(ans, sum(map(int, str(temp))))

print(ans)