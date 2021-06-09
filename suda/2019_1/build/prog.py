n, m, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
for i in range(n):
	b[i] -= 1
level = [0 for i in range(n)]
for i in range(n):
	level[b[i]] += a[i]

s = [set() for i in range(n)]
for i in range(m):
	u, v = map(int, input().split())
	u -= 1
	v -= 1
	if b[u] in s[v]:
		continue
	if b[u] == b[v]:
		continue
	if len(s[v]) == k:
		continue
	s[v].add(b[u])
	level[b[u]] += a[v]

for i in range(n):
	print(level[b[i]], end=' ')
print()