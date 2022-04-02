'''
Author: tusikalanse
Date: 2022-04-02 14:21:03
LastEditTime: 2022-04-02 14:22:06
LastEditors: tusikalanse
Description: 
'''
for case in range(1, 1 + int(input())):
    print("Case #%d:" %case)
    r, c = map(int, input().split())
    print(".." + "+-" * (c - 1) + "+")
    print(".." + "|." * (c - 1) + "|")
    print(("+-" * c + "+\n" + "|." * c + "|\n") * (r - 1) + "+-" * c + "+")