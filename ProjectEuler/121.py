'''
Author: tusikalanse
Date: 2021-08-20 09:29:14
LastEditTime: 2021-08-20 10:00:37
LastEditors: tusikalanse
Description: 
'''
def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

class Rational(object):
    def __init__(self, nominator, denominator):
        self.nominator = nominator
        self.denominator = denominator
    
    def __add__(self, other):
        r = Rational(self.nominator * other.denominator + self.denominator * other.nominator, self.denominator * other.denominator)
        x = gcd(r.nominator, r.denominator)
        r.nominator //= x
        r.denominator //= x
        return r

    def __mul__(self, other):
        r = Rational(self.nominator * other.nominator, self.denominator * other.denominator)
        x = gcd(r.nominator, r.denominator)
        r.nominator //= x
        r.denominator //= x
        return r

    def __str__(self):
        return str(self.nominator) + " / " + str(self.denominator)

dp = [[Rational(0, 1) for i in range(20)] for j in range(20)]

dp[0][0] = Rational(1, 1)

n = 15

for i in range(1, n + 1):
    win = Rational(1, i + 1)
    lost = Rational(i, i + 1)
    for j in range(0, i):
        dp[i][j] += dp[i - 1][j] * lost
        dp[i][j + 1] += dp[i - 1][j] * win

ans = Rational(0, 1)

for j in range(n // 2 + 1, n + 1):
    ans += dp[n][j]

print(ans)
print(ans.denominator // ans.nominator)