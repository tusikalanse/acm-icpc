## 禁止复读

按照题意禁言发起复读的人即可（需要注意数组下标是从0还是1开始，以及如何判断发起复读还是跟随复读）

```python
n, m = map(int, input().split())
vis = [0 for i in range(n)]
s = ['' for i in range(m)]

for i in range(m):
	p, s[i] = input().split()
	p = int(p) - 1
	if i != 0 and (s[i] == s[i - 1] and (i == 1 or s[i - 1] != s[i - 2])):
		vis[p] = 1

cnt = 0
for i in range(n):
	cnt += vis[i]

print(cnt)
for i in range(n):
	if vis[i] == 1:
		print(i + 1, end=' ')
print()
```

## CGG的回文串

显然循环输出"iijj"即可

```python
print(("iijj" * 30000)[: int(input())])
```

## 盖楼大挑战

只需要判断是否同组，是否已经助力过本组，次数是否达到上限即可

```python
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
```

## 消失的高数试卷

只需要记录前缀最大值和后缀最大值，拿走$[l, r]$时查询前$l-1$个人的最大值和$r+1$到结尾的人的最大值即可

```python
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
```

