import random

random.seed('landequality')

def rand(a,b):
  return random.randint(a,b)

def print_case(g):
  res = '%d %d\n' % (len(g), len(g[0]))
  res += ''.join([' '.join(row) + '\n' for row in g])
  return res
  
def random_case(args):
  r, c = int(args['r']), int(args['c'])
  vs = args['vs']
  return print_case([[random.choice(vs) for _ in range(c)] for _ in range(r)])

def single0(args):
  r, c = int(args['r']), int(args['c'])
  g = [[random.choice('12') for _ in range(c)] for _ in range(r)]
  i, j = rand(0, r - 1), rand(0, c - 1)
  g[i][j] = '0'
  return print_case(g)