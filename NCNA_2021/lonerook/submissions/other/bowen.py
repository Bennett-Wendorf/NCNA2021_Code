#!/usr/bin python3
# Translated from bowen.cpp. But unfortunately even pypy3 seems not fast enough.

import sys
from collections import deque

dirKnight = [[-1, 2], [1, 2], [2, 1], [2, -1], [1, -2], [-1, -2], [-2, -1], [-2, 1]]
dirRook = [[-1, 0],[1, 0], [0, 1], [0, -1]]

r, c = [int(x) for x in sys.stdin.readline().split(' ')]
g = [list(sys.stdin.readline().rstrip('\n')) for _ in range(r)]
v = [[False] * c for _ in range(r)]
attacked = [[0] * c for _ in range(r)]

q = deque()
s = max(r, c)

for i in range(r):
  for j in range(c):
    if g[i][j] == 'R':
      v[i][j] = True
      q.append((i, j))
    elif g[i][j] == 'K':
      for di, dj in dirKnight:
        ni, nj = i + di, j + dj
        if ni < 0 or ni >= r or nj < 0 or nj >= c: continue
        attacked[ni][nj] += 1

while len(q) > 0:
  i, j = q.popleft()
  if g[i][j] == 'T':
    print('yes')
    sys.exit(0)
  if g[i][j] == 'K':
    for di, dj in dirKnight:
      ni, nj = i + di, j + dj
      if ni < 0 or ni >= r or nj < 0 or nj >= c: continue
      attacked[ni][nj] -= 1
      if attacked[ni][nj] == 0:
        for ddi, ddj in dirRook:
          nni, nnj = ni, nj
          while True:
            nni += ddi
            nnj += ddj
            if nni < 0 or nni >= r or nnj < 0 or nnj >= c: break
            if v[nni][nnj] and not v[ni][nj]:
              v[ni][nj] = True
              q.append((ni, nj))
            elif g[nni][nnj] == 'K': break
  for di, dj in dirRook:
    ni, nj = i, j
    while True:
      ni += di
      nj += dj
      if ni < 0 or ni >= r or nj < 0 or nj >= c: break
      if v[ni][nj]: continue
      if attacked[ni][nj] == 0:
        v[ni][nj] = True
        q.append((ni, nj))
      if g[ni][nj] == 'K' and not v[ni][nj]: break

print('no')
