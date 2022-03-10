import random

random.seed('streamlag')

def rand(a,b):
  return random.randint(a,b)

def print_case(ts):
  res = '%d\n' % len(ts)
  res += ''.join(['%d %d\n' % (r[0], r[2]) for r in ts])
  return res
  
def random_case(args):
  n = int(args['n'])
  tmin, tmax = int(args['tmin']), int(args['tmax'])
  ts = [(rand(tmin, tmax), rand(1, n), i + 1) for i in range(n)]
  ts = sorted(ts)
  return print_case(ts)
