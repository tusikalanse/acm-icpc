n, m = map(int, input().split())
a = [0] + list(map(int, input().split())) + [0]

for i in range(m):
	l, r = map(int, input().split())
	print(max(max(a[:l]), max(a[r+1:])))