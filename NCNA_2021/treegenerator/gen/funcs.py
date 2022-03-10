import random

random.seed('treegenerator')

def rand(a,b):
  return random.randint(a,b)

def print_case(es, vals, m, qs, rand_nodes=True):
  n = len(es) + 1
  nodes = list(range(1, n + 1))
  if rand_nodes:
    random.shuffle(nodes)
    mapping = [-1] * (n + 1)
    for i in range(n):
      mapping[nodes[i]] = i
  else:
    mapping = [i - 1 for i in range(0, n+1)]
    
  res = '%d %d %d\n' % (n, m, len(qs))
  res += ''.join(['%d %d\n' % (nodes[e[0]], nodes[e[1]]) for e in es])
  res += ''.join(['%d\n' % vals[mapping[i]] for i in range(1, n + 1)])
  res += ''.join(['%d %d\n' % (nodes[q[0]], nodes[q[1]]) for q in qs])
  return res

def rand_vals(n):
  return [rand(0, 9) for _ in range(n)]

def rand_queries(n, q):
  return [(rand(0, n - 1), rand(0, n - 1)) for _ in range(q)]
  
def rand_tree(n):
  edges = []
  for i in range(1, n):
    j = rand(0, i - 1)
    edges.append((i, j))
  return edges

def flower(n, r):
  assert (n - 1) % r == 0
  edges = []
  for g in range((n - 1) / r):
    for j in range(r - 1):
      i = 1 + g*r + j
      edges.append((i, i + 1))
    edges.append((1 + g*r, 0))
  return edges
  
def chain(n):
  return [(i, i+1) for i in range(0, n-1)]
  
def random_tree_case(args):
  n, m, q = int(args['n']), int(args['m']), int(args['q'])
  es = rand_tree(n)
  vals = rand_vals(n)
  qs = rand_queries(n, q)
  return print_case(es, vals, m, qs)

def chain_case(args):
  n, m, q = int(args['n']), int(args['m']), int(args['q'])
  long_query = int(args['long_query']) if 'long_query' in args else 0
  es = chain(n)
  vals = rand_vals(n)
  if long_query == 1:
    qs = []
    while len(qs) < q:
      a, b = rand(0, n//10), rand(n - n//10, n-1)
      if random.random() < 0.5:
        a, b = b, a
      qs.append((a, b))
  else:
    qs = rand_queries(n, q)
  return print_case(es, vals, m, qs)
  
def flower_case(args):
  n, m, q = int(args['n']), int(args['m']), int(args['q'])
  long_query = int(args['long_query']) if 'long_query' in args else 0
  r = int(args['r'])
  es = flower(n, r)
  vals = rand_vals(n)
  if long_query == 1:
    qs = []
    while len(qs) < q:
      bi, bj = -1, -1
      while bi == bj:
        bi, bj = rand(0, (n - 1) // r - 1), rand(0, (n - 1) // r - 1)
      if r < 10 or long_query == 0:
        ri, rj = rand(0, r - 1), rand(0, r - 1)
      else:
        ri, rj = rand(r - r // 10, r - 1), rand(r - r // 10, r - 1)
      qs.append((bi * r + ri + 1, bj * r + rj + 1))
  else:
    qs = rand_queries(n, q)
  return print_case(es, vals, m, qs)
