n, m = map(int, input().split())
vis = [0 for i in range(n)]
s = ['' for i in range(m)]
flag = 0
p, s[0] = input().split()
for i in range(1, m):
	p, s[i] = input().split()
	p = int(p) - 1
	if s[i] == s[i - 1] and flag == 0:
		flag = 1
		vis[p] = 1
	if s[i] != s[i - 1]:
		flag = 0

cnt = 0
for i in range(n):
	cnt += vis[i]

print(cnt)
fir = 0
for i in range(n):
	if vis[i] == 1:
		if fir == 0:
			fir = 1
			print(i + 1, end='')
		else:
			print(' ' + str(i + 1))
print()