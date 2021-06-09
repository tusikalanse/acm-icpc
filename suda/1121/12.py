for _ in range(int(input())):
	x, y = list(map(int, input().split()))
	flag = 1
	for i in range(x, y + 1):
		n = i * i + i + 41
		for j in range(2, n):
			if j * j > n:
				break
			if n % j == 0:
				flag = 0
				break
		if flag == 0:
			break
	if flag:
		print("OK")
	else:
		print("Sorry")