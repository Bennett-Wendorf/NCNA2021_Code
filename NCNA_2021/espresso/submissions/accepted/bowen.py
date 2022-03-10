#!/usr/bin python3

import sys

n, s = [int(x) for x in sys.stdin.readline().split(' ')]
cur = s
ans = 0
for _ in range(n):
  order = sys.stdin.readline().rstrip('\n')
  w = ord(order[0]) - ord('0')
  if len(order) == 2:
    w += 1
  if cur - w < 0:
    cur = s
    ans += 1
  cur -= w
print (ans)
