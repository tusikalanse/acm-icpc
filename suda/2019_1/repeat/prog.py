n, m = map(int, input().split())
vis = [0 for i in range(n)]
s = ['' for i in range(m)]
p, s[0] = input().split()
for i in range(1, m):
	p, s[i] = input().split()
	p = int(p) - 1
	if s[i] == s[i - 1] and (i == 1 or s[i - 1] != s[i - 2]):
		vis[p] = 1

cnt = 0
for i in range(n):
	cnt += vis[i]

print(cnt)
for i in range(n):
	if vis[i] == 1:
		print(i + 1, end=' ')
print()
