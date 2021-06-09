n = int(input())
t = int(n * (n - 1) / 2)
s = [set() for i in range(t)]
for i in range(t):
	x = list(map(int, input().split()))[1:]
	s[i] = set(x)
s.sort()

if t == 1:
	print(1, end=' ')
	l = list(s[0])
	print(l[0], sep=' ')
	l = l[1:]
	print(len(l), end=' ')
	print(*l, sep=' ')
	exit()


ans = list()
l = list(s[0] & s[1])
l.sort()
ans.append(l);
sp = set(l);
for i in range(t):
	l = list(s[i] - sp)
	if(len(l) == len(s[i])):
		continue
	l.sort()
	if l and l not in ans:
		ans.append(l)

for i in ans:
	print(len(i), end=' ')
	print(*i, sep=' ')