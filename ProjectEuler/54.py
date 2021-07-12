'''
Author: tusikalanse
Date: 2021-07-12 08:17:32
LastEditTime: 2021-07-12 08:19:46
LastEditors: tusikalanse
Description: 
FilePath: /ProjectEuler/54.py
'''
'''
Author: tusikalanse
Date: 2021-07-12 08:17:32
LastEditTime: 2021-07-12 08:17:32
LastEditors: tusikalanse
Description: 
FilePath: /ProjectEuler/54.py
'''
def is_suit(card) -> bool:
    return len(set(card)) == 1

def get_level(card):
    num = []
    s = []
    for i in range(5):
        if (card[i][0] == 'T'):
            num.append(10)
        elif (card[i][0] == 'J'):
            num.append(11)
        elif (card[i][0] == 'Q'):
            num.append(12)
        elif (card[i][0] == 'K'):
            num.append(13)
        elif (card[i][0] == 'A'):
            num.append(14)
        else:
            num.append(int(card[i][0]))
        s.append(card[i][-1])
    num = sorted(num)
    suited = is_suit(s)
    size = len(set(num))
    if suited:
        if size == 5:
            if num[0] == 10:
                return [9, num[0]]
            elif num[0] + 4 == num[4]:
                return [8, num[0]]
            elif num[0] == 2 and num[3] == 5 and num[4] == 14:
                return [8, 1]
            else:
                return [5, num[4], num[3], num[2], num[1], num[0]]
        else:
            return [5, num[4], num[3], num[2], num[1], num[0]]
    else:
        if size == 5:
            if num[0] + 4 == num[4]:
                return [4, num[0]]
            elif num[0] == 2 and num[3] == 5 and num[4] == 14:
                return [4, 1]
            else:
                return [0, num[4], num[3], num[2], num[1], num[0]]
        elif size == 4:
            if num[0] == num[1]:
                return [1, num[0], num[4], num[3], num[2]]
            elif num[1] == num[2]:
                return [1, num[1], num[4], num[3], num[0]]
            elif num[2] == num[3]:
                return [1, num[2], num[4], num[1], num[0]]
            elif num[3] == num[4]:
                return [1, num[3], num[2], num[1], num[0]]
            else:
                assert(False)
        elif size == 3:
            if num[0] == num[2]:
                return [3, num[0], num[4], num[3]]
            elif num[1] == num[3]:
                return [3, num[1], num[4], num[0]]
            elif num[2] == num[4]:
                return [3, num[2], num[1], num[0]]
            elif num[0] == num[1]:
                if num[2] == num[3]:
                    return [2, num[2], num[0], num[4]]
                elif num[3] == num[4]:
                    return [2, num[3], num[0], num[2]]
                else:
                    assert(False)
            elif num[1] == num[2]:
                assert(num[3] == num[4])
                return [2, num[3], num[1], num[0]]
            else:
                assert(False)
        elif size == 2:
            if num[0] == num[3]:
                return [7, num[0], num[4]]
            elif num[1] == num[4]:
                return [7, num[1], num[0]]
            elif num[0] == num[2] and num[3] == num[4]:
                return [6, num[0], num[3]]
            elif num[0] == num[1] and num[2] == num[4]:
                return [6, num[2], num[0]]
            else:
                assert(False)

cnt = 0
for i in range(1000):
    line = input().split()
    A = line[:5]
    B = line[5:]
    print(A, B)
    cnt += get_level(A) > get_level(B)

print(cnt)