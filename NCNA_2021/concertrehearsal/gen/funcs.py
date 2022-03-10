import random

random.seed('concertrehearsal')

def rand(a,b):
  return random.randint(a,b)

def vary(v):
  return rand(v // 100 * 95, v)  

def print_case(n, p, k, ds):
  res = '%d %d %d\n' % (n, p, k)
  res += ''.join(['%d\n' % d for d in ds])
  return res

def random_case(args):
  n, p, k = int(args['n']), int(args['p']), int(args['k'])
  dmin, dmax = int(args['dmin']), int(args['dmax'])
  fixed = bool(args['fixed']) if 'fixed' in args else False
  if not fixed: n, p, k = vary(n), vary(p), vary(k)
  dmax = min(dmax, p)
  dmin = min(dmax, dmin)
  ds = [rand(dmin, dmax) for _ in range(n)]
  return print_case(n, p, k, ds)
