x = int(input())
a = []
b = dict()
for i in range(x):
	s = input()
	a.append(eval(s))
	if(a[i] not in b):
		b[a[i]] = 1
	else:
		b[a[i]] += 1

for i in range(x):
	print("%d "%b[a[i]], end = '')
print()