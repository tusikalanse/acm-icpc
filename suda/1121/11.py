for _ in range(int(input())):
	n = int(input())
	cnt = 0
	for i in range(3, n):
		if i + i >= n:
			break
		flag = 1
		for j in range(2, i):
			if j * j > i:
				break
			if i % j == 0:
				flag = 0
		for j in range(2, n - i):
			if j * j > (n - i):
				break
			if (n - i) % j == 0:
				flag = 0
		cnt += flag
	print(cnt)