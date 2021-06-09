from math import *
n = int(input())
k = int(input())
lst = []
for i in range(n):
	l = float(input())
	lst.append(l)
l, r = 0, max(lst)
for _ in range(1000):
	mid = (l + r) / 2
	cnt = 0
	for i in lst:
		cnt += floor(i / mid)
	if cnt >= k:
		l = mid
	else:
		r = mid
print("%.2f" % (int(l * 100) / 100.0))