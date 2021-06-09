from math import sqrt

n = int(input())
lst = []
for i in range(n):
	l = [int(i) for i in input().split()]
	lst.append(l)

lst.sort(key=lambda x: x[0])

dis, n1, n2 = 0, 0, 0

for i in range(n):
	for j in range(i + 1, n):
		tmp = (lst[i][1] - lst[j][1]) * (lst[i][1] - lst[j][1]) + (lst[i][2] - lst[j][2]) * (lst[i][2] - lst[j][2])
		if tmp > dis or (tmp == dis and (i + j < n1 + n2 or (i + j == n1 + n2 and i < n1))):
			dis, n1, n2 = tmp, i, j

print("%d %d %.2f" % (n1 + 1, n2 + 1, sqrt(dis)))