n, m = list(map(int, input().split()))
s = input()
cnt = 0
for i in s:
	cnt += i == '1'
print(cnt * m)