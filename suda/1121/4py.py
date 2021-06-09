for _ in range(int(input())):
	s = set()
	for i in range(list(map(int, input().split()))[-1]):
		a = list(map(int, input().split()))[-1]
		s.add(a)
	print(len(s))