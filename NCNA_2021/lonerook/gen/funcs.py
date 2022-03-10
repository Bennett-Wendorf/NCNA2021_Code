import random
import os

random.seed('lonerook')
os.system('g++ -o bowen_map bowen_map.cpp -O2')

KNIGHT_DIRS = [[-1, 2], [1, 2], [2, 1], [2, -1], [1, -2], [-1, -2], [-2, -1], [-2, 1]]
SPIRAL_DIRS = [[1, 0], [0, 1], [-1, 0], [0, -1]]

def rand(a,b):
  return random.randint(a,b)

def get_map(g):
  with open('map.in', 'w') as f:
    f.write(print_case(g))
  os.system('./bowen_map < map.in > map.out')
  with open('map.out', 'r') as f:
    mg = f.readlines()
  #os.remove('map.in')
  #os.remove('map.out')
  return mg

def print_case(g):
  res = '%d %d\n' % (len(g), len(g[0]))
  res += ''.join([''.join(row) + '\n' for row in g])
  return res

def rotate_board(g):
  r, c = len(g), len(g[0])
  ng = [['.'] * r for _ in range(c)]
  for i in range(r):
    for j in range(c):
      ng[j][i] = g[i][j]
  return ng
  
def valid(r, c, i, j):
  return i >= 0 and i < r and j >= 0 and j < c
  
def random_case(args):
  r, c = int(args['r']), int(args['c'])
  density = float(args['density'])
  g = [['.'] * c for _ in range(r)]
  return print_case(g)

def fill_random_knights(g, prob):
  r, c = len(g), len(g[0])
  for i in range(r):
    for j in range(c):
      if g[i][j] == '.':
        ok = True
        for (di, dj) in KNIGHT_DIRS:
          ni, nj = i + di, j + dj
          if not valid(r, c, ni, nj): continue
          if g[ni][nj] == 'R':
            ok = False
            break
        if ok and random.random() < prob:
          g[i][j] = 'K'

def fill_yes(g):
  mg = get_map(g)
  r, c = len(g), len(g[0])
  candidates = []
  for i in range(r - r//10, r):
    for j in range(c - c//10, c):
      if mg[i][j] == '*': # reachable square
        candidates.append((i, j))
  assert len(candidates) > 0
  i, j = random.choice(candidates)
  g[i][j] = 'T'    
  
def fill_no(g):
  mg = get_map(g)
  r, c = len(g), len(g[0])
  candidates = []
  for i in range(r - r//10, r):
    for j in range(c - c//10, c):
      if mg[i][j] == '@': # unreachable square not attacked by a knight
        candidates.append((i, j))
  if len(candidates) == 0:
    print ('warning: every unreachable square is attacked by a knight')
    for i in range(r - r//10, r):
      for j in range(c - c//10, c):
        if mg[i][j] == '.':
          candidates.append((i, j))
  assert len(candidates) > 0
  i, j = random.choice(candidates)
  g[i][j] = 'T'

def group_of_4(args):
  seed = int(args['seed'])
  r, c = int(args['r']), int(args['c'])
  yes = int(args['yes'])
  prob = float(args['prob'])
  random.seed(seed)
  
  assert r % 6 == 0 and c % 6 == 0
  g = [['.'] * c for _ in range(r)]
  for i in range(r // 6):
    for j in range(c // 6):
      g[i * 6 + 2][j * 6 + 2] = 'K'
      g[i * 6 + 2][j * 6 + 3] = 'K'
      g[i * 6 + 3][j * 6 + 2] = 'K'
      g[i * 6 + 3][j * 6 + 3] = 'K'
  g[2][2] = 'R'
  
  fill_random_knights(g, prob)
  if yes == 1:
    fill_yes(g)
  else:
    fill_no(g)
  return print_case(g)
  
  
def stripes(args):
  seed = int(args['seed'])
  r, c = int(args['r']), int(args['c'])
  yes = int(args['yes'])
  prob = float(args['prob'])
  random.seed(seed)
  
  assert r % 5 == 0 and c % 5 == 0
  g = [['.'] * c for _ in range(r)]
  for i in range(r // 5):
    for j in range(3, c - 3):
      g[i * 5 + 2][j] = 'K'
  g[2][0] = 'R'
  
  fill_random_knights(g, prob)
  if yes == 1:
    fill_yes(g)
  else:
    fill_no(g)
  return print_case(g)
  
  
def fences(args):
  r, c = int(args['r']), int(args['c'])
  
  g = [['.'] * c for _ in range(r)]
  for i in range(r):
    g[i][3] = g[i][4] = 'K'
  g[r // 2][3] = g[r // 2][4] = '.'
  
  for j in range(7, c, 3):
    for i in range(r):
      g[i][j] = 'K'
      
  g[1][c - 2] = 'K'
  g[0][0] = 'R'
  g[0][c - 1] = 'T'
  return print_case(g)
  
def spiral(args):
  r, c = int(args['r']), int(args['c'])
  knight = int(args['knight'])
  g = [['.'] * c for _ in range(r)]
  i, j, d = 0, 3, 0
  xlen = 7
  xlenh = 3
  while True:
    stepped = False
    while True:
      nd = (d + 1) % 4
      g[i][j] = 'K'
      mi, mj = i + SPIRAL_DIRS[nd][0], j + SPIRAL_DIRS[nd][1]
      if valid(r, c, mi, mj):
        g[mi][mj] = 'M'
      #if knight == 1:
      #  mi, mj = i + SPIRAL_DIRS[nd][0] * xlenh, j + SPIRAL_DIRS[nd][1] * xlenh
      #  if valid(r, c, mi, mj):
      #    g[mi][mj] = 'X'
        
      ni, nj = i + SPIRAL_DIRS[d][0], j + SPIRAL_DIRS[d][1]
      nxi, nxj = i + xlen * SPIRAL_DIRS[d][0], j + xlen * SPIRAL_DIRS[d][1]
      if valid(r, c, nxi, nxj) and g[nxi][nxj] != 'K':
        stepped = True
        i, j = ni, nj
      else:
        break
    if not stepped: break
    d = (d + 1) % 4
  
  d = (d + 3) % 4
  g[i + SPIRAL_DIRS[d][0] * xlenh][j + SPIRAL_DIRS[d][1] * xlenh] = 'T'
  
  """
  for i in range(r):
    for j in range(c):
      if g[i][j] == '.' and ((i - 1 >= 0 and g[i - 1][j] == 'K') or (j - 1 >= 0 and g[i][j - 1] == 'K')):
        g[i][j] = '*'
  """
  for i in range(r):
    for j in range(c):
      if g[i][j] == 'M':
        g[i][j] = 'K'
    
  g[0][0] = 'R'
  return print_case(g)
    

def zigzag(args):
  r, c = int(args['r']), int(args['c'])
  rg = 8
  cg = 6
  assert r % rg == 0
  assert c % cg == 0
  g = [['.'] * c for _ in range(r)]
  
  for bi in range(0,r,rg):
    ei = bi + rg - 1
    for bj in range(0,c,cg):
      for i in range(bi, ei + 1):
        g[i][bj + cg - 1] = 'K'
      for j in range(0, cg):
        g[bi][bj + j] = g[ei][bj + j] = 'K'
      block_row = bi + 1 if (bj // 5) % 2 == 0 else bi + 6
      g[block_row][bj + cg - 2] = 'K'
  
  for bi in range(0,r,rg):
    brow = bi + rg - 2
    bcol = c - 2 if (bi // rg) % 2 == 0 else 0
    for i in range(4):
      for j in range(2):
        if brow + i < r and bcol + j < c:
          g[brow + i][bcol + j] = '.'

  g[3][0] = 'R'
  g[r - 1][c - 1] = 'T'
  return print_case(g)  

def rot(n, x, y, rx, ry):
  if ry == 0:
     if rx == 1:
        x, y = n - 1 - x, n - 1 - y
     x, y = y, x
  return x, y

def d2xy(n, d):
  t = d
  x, y = 0, 0
  s = 1
  while s < n:
    rx = 1 & (t // 2)
    ry = 1 & (t ^ rx)
    x, y = rot(s, x, y, rx, ry)
    x += s * rx
    y += s * ry
    t = t // 4
    s *= 2
  return x, y


def dig_path_hilbert(g, x, y, xn, yn, s=9):
  r, c = len(g), len(g[0])
  s2 = s // 2
  dx, dy = xn - x, yn - y
  x, y, xn, yn = x * s + s2 + 2 * dx, y * s + s2 + 2 * dy, xn * s + s2 - 2 * dx, yn * s + s2 - 2 * dy
  while x != xn or y != yn:
    if x < r and y < c:
      g[x][y] = '.'
    x, y = x + dx, y + dy
    
def hilbert(args):
  r, c = int(args['r']), int(args['c'])
  fr, fc = int(args['fr']), int(args['fc'])
  s = 9
  s2 = s // 2
  assert r % s == 0 and c % s == 0
  assert fr % s == 0 and fc % s == 0
  assert bin(r // s)[2:].count('1') == 1
  assert bin(c // s)[2:].count('1') == 1
  g = [['.'] * fc for _ in range(fr)]
  
  for bi in range(0,fr,s):
    for bj in range(0,fc,s):
      for i in range(bi, bi+s):
        g[i][bj] = g[i][bj + s - 1] = 'K'
      for j in range(bj, bj+s):
        g[bi][j] = g[bi + s - 1][j] = 'K'
      g[bi + s2][bj + s2] = 'K'
 
      for d in range(4):
        i, j = bi + s2 + SPIRAL_DIRS[d][0], bj + s2 + SPIRAL_DIRS[d][1]
        g[i][j] = 'K'
  
  for d in range((r // s) * (c // s)):
    x, y = d2xy(r // s, d)
    xn, yn = d2xy(r // s, d + 1)
    dig_path_hilbert(g, x, y, xn, yn)
  
  cur_dx = 1
  bi, bj = r // s - 1, 0
  while bj * s < fc:
    ended = False
    while not ended:
      nbi = bi + cur_dx
      nbj = bj
      if nbi < 0 or (nbi < (r // s) and nbj < (c // s)) or nbi >= (fr // s):
        nbi = bi
        nbj = bj + 1
        cur_dx = -cur_dx
        ended = True
      dig_path_hilbert(g, bi, bj, nbi, nbj)
      bi, bj = nbi, nbj
      
  g[s2][s2] = 'R'
  g[fr - 1 - s2][fc - 1 - s2] = 'T'
  return print_case(g)  

def dig_path_hilbert2(g, x, y, xn, yn, s=11):
  r, c = len(g), len(g[0])
  s2 = s // 2
  dx, dy = xn - x, yn - y
  x, y, xn, yn = x * s + s2 + 4 * dx, y * s + s2 + 4 * dy, xn * s + s2 - 4 * dx, yn * s + s2 - 4 * dy
  while x != xn or y != yn:
    for ddx, ddy in SPIRAL_DIRS:
      xx, yy = x + ddx, y + ddy
      if xx >= 0 and yy >= 0 and xx < r and yy < c:
        g[xx][yy] = '.'
    x, y = x + dx, y + dy

def hilbert2(args):
  r, c = int(args['r']), int(args['c'])
  fr, fc = int(args['fr']), int(args['fc'])
  s = 11
  s2 = s // 2
  assert r % s == 0 and c % s == 0
  assert fr % s == 0 and fc % s == 0
  assert bin(r // s)[2:].count('1') == 1
  assert bin(c // s)[2:].count('1') == 1
  g = [['.'] * fc for _ in range(fr)]
  
  for bi in range(0,fr,s):
    for bj in range(0,fc,s):
      for i in range(bi, bi+s):
        g[i][bj] = g[i][bj + s - 1] = 'K'
      for j in range(bj, bj+s):
        g[bi][j] = g[bi + s - 1][j] = 'K'
      
      if bi > 0 or bj > 0:
        for d in range(8):
          i, j = bi + s2 + KNIGHT_DIRS[d][0], bj + s2 + KNIGHT_DIRS[d][1]
          g[i][j] = 'K'
  
  for d in range((r // s) * (c // s)):
    x, y = d2xy(r // s, d)
    xn, yn = d2xy(r // s, d + 1)
    dig_path_hilbert2(g, x, y, xn, yn)
  
  cur_dx = 1
  bi, bj = r // s - 1, 0
  while bj * s < fc:
    ended = False
    while not ended:
      nbi = bi + cur_dx
      nbj = bj
      if nbi < 0 or (nbi < (r // s) and nbj < (c // s)) or nbi >= (fr // s):
        nbi = bi
        nbj = bj + 1
        cur_dx = -cur_dx
        ended = True
      dig_path_hilbert2(g, bi, bj, nbi, nbj)
      bi, bj = nbi, nbj

  g[s2][s2] = 'R'
  g[s2][fc - 1 - s2] = 'T'
  return print_case(g)  

def capture_pass(args):
  r, c = int(args['r']), int(args['c'])
  yes = int(args['yes'])
  rotate = int(args['rotate'])
  pattern = [
    'KKK.KKKKKKKKK',
    'K...........K',
    'K...........K',
    'K...........K',
    'K...........K',
    'K.....KKK...K',
    'K..........KK',
    'K...KKK....KK',
    'K..........KK',
    'K..........KK',
    'K..........KK',
    'K..........KK',
    'K..........KK',
    'KKKKKKKKK.KKK',
  ]
  rg, cg = len(pattern), len(pattern[0])
  assert r % rg == 0 and c % cg == 0
  g = [['.'] * c for _ in range(r)]
  for bi in range(r // rg):
    for bj in range(c // cg):
      for i in range(rg):
        for j in range(cg):
          pi = i if bj % 2 == 0 else rg - 1 - i
          pj = j if bi % 2 == 0 else cg - 1 - j
          g[bi * rg + i][bj * cg + j] = pattern[pi][pj]
  for bj in range(c // cg):
    rb1, rb2 = r - 2, r - 3
    rt1, rt2 = 1, 2
    if bj % 2 == 1:
      rb1, rt1 = rt1, rb1
      rb2, rt2 = rt2, rb2
    
    g[rt1][bj * cg] = g[rt2][bj * cg] = '.'
    g[rb1][bj * cg + cg - 1] = g[rb2][bj * cg + cg - 1] = '.'
    g[rb1][bj * cg + cg - 2] = g[rb2][bj * cg + cg - 2] = '.'
      
  g[3][4] = 'R'
  if yes == 1:
    g[0][c - 1] = 'T'
  else:
    g[7][c - 7] = 'T'
  
  if rotate == 1:
    g = rotate_board(g)
  return print_case(g)
  
  
def chess(args):
  r, c = int(args['r']), int(args['c'])
  seed = int(args['seed'])
  yes = int(args['yes'])
  prob = float(args['prob'])
  g = [['.'] * c for _ in range(r)]
  for i in range(r):
    for j in range(c):
      if (i + j) % 2 == 0:
        g[i][j] = 'K'
  g[0][0] = 'R'
  
  random.seed(seed)
  fill_random_knights(g, prob)
  if yes == 1:
    fill_yes(g)
  else:
    fill_no(g)
  return print_case(g)