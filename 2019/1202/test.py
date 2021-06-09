def gao(i, j, k):
	val = i ** 3 + j ** 3 + k ** 3
	f, v = 0, 0
	if val >= 0 and val <= 200:
		f = 1
		if k <= 500 and i >= -500:
			v = 2
		else:
			v = 1
	return f, v, val


vis = [0 for i in range(201)]


for i in range(-1000, 1001):
	print(i)
	for j in range(i, 1001):
		for k in range(j, 1001):
			f, v, val = gao(i, j, k)
			if f: vis[val] = max(vis[val], v)


cnt1, cnt2 = 0, 0

for i in range(201):
	if vis[i] >= 2: cnt2 += 1
	if vis[i] >= 1: cnt1 += 1

print(cnt1, cnt2)
