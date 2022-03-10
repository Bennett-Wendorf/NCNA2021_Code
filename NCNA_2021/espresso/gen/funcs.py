import random

random.seed('espresso')

def rand(a,b):
  return random.randint(a,b)

def print_case(s, es):
  res = '%d %d\n' % (len(es), s)
  res += ''.join(['%s\n' % e for e in es])
  return res

def random_case(args):
  n, s = int(args['n']), int(args['s'])
  es = [random.choice(['1', '1L', '2', '2L', '3', '3L', '4', '4L']) for _ in range(n)]
  return print_case(s, es)  
