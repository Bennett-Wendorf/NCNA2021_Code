#!/usr/bin python3

import sys

p, q = [int(x) for x in sys.stdin.readline().split(' ')]
pos = sys.stdin.readline().rstrip('\n')

fr, fs = -1, -1
cases = 0
for r in range(1, 10):
  for s in range(r + 1, 10):
    cards = sorted([p, q, r, s])
    curpos = ''.join(['A' if x == p or x == q else 'B' for x in cards])
    if curpos == pos:
      cases += 1
      fr, fs = r, s

if cases != 1:
  print(-1)
else:
  print(fr, fs)
