n, m = map(int, input().split())
pre = [0 for i in range(n + 2)]
suf = [0 for i in range(n + 2)]
a = [0] + list(map(int, input().split()))
for i in range(1, n + 1):
	pre[i] = max(pre[i - 1], a[i])

for i in range(n, 0, -1):
	suf[i] = max(suf[i + 1], a[i])

for i in range(m):
	l, r = map(int, input().split())
	print(max(pre[l - 1], suf[r + 1]))
