n, m, k, q = list(map(int, input().split()))
s = input()
tmp, ans = 0, 0
for i in s:
	if i == '0':
		if tmp >= k:
			ans += q * tmp * tmp
		tmp = 0
	else:
		tmp += 1
		ans += m
if tmp >= k:
	ans += q * tmp * tmp
print(ans)