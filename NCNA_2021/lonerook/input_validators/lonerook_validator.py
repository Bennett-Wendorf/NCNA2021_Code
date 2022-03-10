#!/usr/bin/python3

import sys
import re

ln = sys.stdin.readline()
assert re.match('^[1-9][0-9]* [1-9][0-9]*\n$', ln)
r, c = [int(x) for x in ln.split(' ')]

dirs = [[-1, 2], [1, 2], [2, 1], [2, -1], [1, -2], [-1, -2], [-2, -1], [-2, 1]]
count_K = 0
count_R = 0
count_T = 0
g = []
ri, rj = -1, -1
for i in range(r):
  ln = sys.stdin.readline()
  g.append(ln)
  assert re.match('^[.RKT]+$', ln)
  count_K += ln.count('K')
  count_R += ln.count('R')
  count_T += ln.count('T')
  if ln.count('R') > 0:
    ri, rj = i, ln.index('R')
    #print (ri, rj)

assert sys.stdin.readline() == ''

assert 1 <= count_K    
assert 1 == count_R
assert 1 == count_T

for d in range(8):
  ni, nj = ri + dirs[d][0], rj + dirs[d][1]
  if ni < 0 or nj < 0 or ni >= r or nj >= c: continue
  #print (ri, rj, ni, nj)
  assert g[ni][nj] != 'K'

sys.exit(42)
