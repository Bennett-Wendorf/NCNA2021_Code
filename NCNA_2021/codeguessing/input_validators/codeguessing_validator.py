#!usr/bin/python3

# Ensures that game scenario is valid.

import sys
import re

ln = sys.stdin.readline()
assert re.match('^[1-9] [1-9]\n$', ln)
p, q = [int(v) for v in ln.split(' ')]
assert p < q

ln = sys.stdin.readline()
assert re.match('^[AB]{4}\n$', ln)
pos = ln.rstrip('\n')
assert pos.count('A') == 2

cases = 0
for r in range(1,10):
  if r == p or r == q: continue
  for s in range(1,10):
    if s == p or s == q: continue
    curpos = [('A' if v == p or v == q else 'B') for v in sorted([p, q, r, s])]
    if ''.join(curpos) == pos:
      cases += 1

assert cases >= 1
sys.exit(42)
