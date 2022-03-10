#!/usr/bin python3

import sys

n, p, k = [int(x) for x in sys.stdin.readline().split(' ')]
d = [0] * (2 * n + 1)
for i in range(1, n+1):
  d[i] = int(sys.stdin.readline())
  d[i + n] = d[i]
for i in range(1, 2*n+1):
  d[i] += d[i - 1]
nxt = [-1] * (n + 1)
last_day = [0] * (n + 1)
day_pass = [0] * (n + 1)

one_pass = d[n]
base_pass = p // one_pass

for i in range(1, n+1):
  rem = p % one_pass
  l, r = i, i + n - 1
  while l <= r:
    m = (l + r) // 2
    t = d[m] - d[i - 1]
    if t > rem: r = m - 1
    else: l = m + 1
  nxt[i] = l - n if l > n else l

cur, day = 1, 1
cycled = False
ans = 0

while k > 0:
  if last_day[cur] > 0 and not cycled:
    cycled = True
    cycle_pass = day_pass[day - 1] - day_pass[last_day[cur] - 1]
    cycle_day = day - last_day[cur]
    ans += k // cycle_day * cycle_pass
    k %= cycle_day
    if k == 0: break
  last_day[cur] = day
  ans += base_pass
  if nxt[cur] < cur: ans += 1
  cur = nxt[cur]
  if not cycled:
    day_pass[day] = ans
    day += 1
  k -= 1
  
print(ans)
