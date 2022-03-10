import random

random.seed('wordpuzzle')

MAX_TLEN = 50

def rand(a,b):
  return random.randint(a,b)

def print_case(p, t):
  return '%s\n%s\n' % (p, t)

def rand_str(l, cmax):
  return ''.join([chr(ord('a') + rand(0, cmax-1)) for _ in range(l)])
  
def random_substr(args):
  n = int(args['n'])
  prob = float(args['prob'])
  cmax = int(args['cmax'])
  
  p = rand_str(n, cmax)
  t = []
  for c in p:
    if len(t) == MAX_TLEN: break
    if random.random() < prob:
      t.append(c)
  t = ''.join(t)
  i = rand(0, len(t) - 1)
  t = t[i:] + t[:i]
  return print_case(p, t)

def fib_seq(args):
  n, m = int(args['n']), int(args['m'])
  
  x = 'a'
  y = 'b'
  t = ''
  while len(y) < n:
    x, y = y, x + y
    if len(x) >= m:
      t = x[:m]
  
  return print_case(x[:n], t)
