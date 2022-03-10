#!/usr/bin python3
# rewritten from zapray.cpp

import sys
import math

g = []

def visible(i, j, p, q):
  x, y = i, j
  while x != p or y != q:
    if g[x][y] == '#':
      return False
    diagcross = (x + 1 - i) * (q - j) - (y + 1 - j) * (p - i)
    if diagcross <= 0: x += 1
    if diagcross >= 0: y += 1
  return True
      
def get_dist(i, j, p, q):
  if visible(i, j, p, q):
    return math.sqrt((p - i) * (p - i) + (q - j) * (q - j))
  return -1

r, c = [int(x) for x in sys.stdin.readline().split(' ')]
for i in range(r):
  g.append(list(sys.stdin.readline().rstrip('\n')))

d = [[[[0] * (c + 1) for _ in range(r + 1)] for _ in range(c)] for _ in range(r)]
for i in range(r):
  for j in range(c):
    for p in range(i+1, r+1):
      for q in range(j+1, c+1):
        d[i][j][p][q] = get_dist(i, j, p, q)

ans = [[0] * (c + 1) for _ in range(r + 1)]

for i in range(1, r+1): ans[i][0] = i
for j in range(1, c+1): ans[0][j] = j
for i in range(1, r+1):
  for j in range(1, c+1):
    ans[i][j] = min(ans[i-1][j], ans[i][j-1]) + 1
    for p in range(i):
      for q in range(j):
        if d[p][q][i][j] != -1:
          ans[i][j] = min(ans[i][j], ans[p][q] + d[p][q][i][j])

print('{:.6f}'.format(ans[r][c]));
