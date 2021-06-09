n, m = list(map(int, input().split()))
lst = []
while m:
	m -= 1
	l = list(map(int, input().split()))
	lst.append(l)
lst.sort(key=lambda x: x[0])
ans = 0
for i in lst:
	if n // i[0] > i[1]:
		n -= i[0] * i[1]
		ans += i[1]
	else:
		ans += n // i[0]
		n %= i[0]
print(ans)