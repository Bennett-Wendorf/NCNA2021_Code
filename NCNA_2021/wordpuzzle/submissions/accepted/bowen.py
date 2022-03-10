#!/usr/bin python3
import sys

mod = int(1e9) + 7

p = sys.stdin.readline().rstrip('\n')
s = sys.stdin.readline().rstrip('\n')
n = len(s)

ans = 0
solved = set()
for _ in range(n):
  if s not in solved:
    solved.add(s)
    dp = [0] * (n + 1)
    dp[0] = 1
    for i in range(1, len(p) + 1):
      cp = p[i - 1]
      for j in range(n - 1, -1, -1):
        cs = s[j]
        if cs == cp:
          dp[j + 1] += dp[j]
          dp[j + 1] %= mod
    ans += dp[n]
    ans %= mod
  s = s[1:] + s[:1]

print (ans)
