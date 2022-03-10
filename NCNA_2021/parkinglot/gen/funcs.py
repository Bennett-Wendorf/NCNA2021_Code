import random

random.seed('parkinglot')

def rand(a,b):
  return random.randint(a,b)

def print_case(g):
  res = '%d %d\n' % (len(g), len(g[0]))
  res += ''.join([''.join(row) + '\n' for row in g])
  return res
  
def rand_graph(r, c, prob):
  g = [['.'] * c for _ in range(r)]
  for i in range(r):
    for j in range(c):
      if random.random() < prob:
        g[i][j] = '#'
  return g

def random_case(args):
  r, c = int(args['r']), int(args['c'])
  prob = float(args['prob'])
  return print_case(rand_graph(r, c, prob))

def path_to(g, i, j, x, y):
  if i == x or j == y:
    return
  a = y - j
  b = i - x
  c = x * j - i * y
  
  vj = j
  for ii in range(i, x):
    jj = (-c - a * (ii + 1)) // b;
    vje = jj if (-c - a * (ii + 1)) % b != 0 else jj - 1
    for v in range(vj, vje + 1):
      g[ii][v] = '.'
    vj = jj
  
def random_path(args):
  r, c = int(args['r']), int(args['c'])
  knot = int(args['knot'])
  i, j = 0, 0
  g = [['#' for _ in range(c)] for _ in range(r)]
  max_d = max(r, c) // knot
  cur_knot = 0
  while cur_knot < knot:
    di = rand(1, r - i - (knot - cur_knot))
    di = min(di, max_d)
    dj = rand(1, c - j - (knot - cur_knot))
    dj = min(dj, max_d)
    path_to(g, i, j, i + di, j + dj)
    i, j = i + di, j + dj
    cur_knot += 1
  path_to(g, i, j, r, c)
  return print_case(g)

def given_path(args):
  r, c = int(args['r']), int(args['c'])
  pts = [int(v) for v in args['points'].split(';')]
  g = [['#' for _ in range(c)] for _ in range(r)]
  n = len(pts) // 2
  i, j = 0, 0
  for pi in range(n):
    x, y = pts[2 * pi + 0], pts[2 * pi + 1]
    path_to(g, i, j, x, y)
    i, j = x, y
  path_to(g, i, j, r, c)
  return print_case(g)