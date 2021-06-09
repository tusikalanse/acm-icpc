for _ in range(int(input())):
	ans = 0
	n = int(input())
	lst = list(map(int, input().split()))
	for i in range(n):
		if lst[i] > 0:
			ans += lst[i]
		else:
			ans += (i + 1) * lst[i]
	print(ans)