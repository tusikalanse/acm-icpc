T = int(input())
for _ in range(T):
  n, z = map(int, input().split())
  mn = z**n
  a, b = 0, 0
  for y in range(1, z):
    x1 = int((z**n - y**n) ** (1 / n))
    x2 = x1 + 1
    if x1 < y:
      cur = abs(z**n - y ** n - x1**n)
      if cur < mn:
        mn, a, b = cur, x1, y
    if x2 < y:
      cur = abs(z**n - y **n - x2**n)
      if cur < mn:
        mn, a, b = cur, x2, y
  print(a, b, mn)


