'''
Author: tusikalanse
Date: 2021-09-08 10:04:41
LastEditTime: 2021-09-08 10:09:13
LastEditors: tusikalanse
Description: 
'''
p = 10 ** 16

N = int(1e5 + 10)
n = int(1e5)

notprime = [0] * N
prime = [0] * N

def getprime():
    notprime[1] = 1
    for i in range(2, N):
        if not notprime[i]:
            prime[0] += 1
            prime[prime[0]] = i

        for j in range(1, prime[0] + 1):
            if i * prime[j] >= N:
                break
            notprime[i * prime[j]] = 1
            if i % prime[j] == 0:
                break

if __name__ == "__main__":
    sum = 0
    total = 0

    getprime()
    for i in range(1, prime[0] + 1):
        if prime[i] <= n:
            total += prime[i]
            if pow(10, p, 9 * prime[i]) == 1:
                sum += prime[i]

    print(sum, total, total - sum)