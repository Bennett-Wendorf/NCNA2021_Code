import random

random.seed('bracketpairing')

def rand(a,b):
  return random.randint(a,b)

def random_brackets(n):
  if n == 0: return ''
  p = rand(1, n // 2)
  brs = random.choice(['()', '[]', '{}', '<>'])
  return brs[0] + random_brackets((p - 1) * 2) + brs[1] + random_brackets(n - p * 2)
    
def random_valid(args):
  n, q = int(args['n']), int(args['q'])
  s = list(random_brackets(n))
  indices = range(0, n)
  random.shuffle(indices)
  for i in range(0, q):
    s[indices[i]] = '?'
  return ''.join(s) + '\n'
