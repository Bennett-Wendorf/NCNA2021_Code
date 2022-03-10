import random

random.seed('evensubstrings')

def rand(a,b):
  return random.randint(a,b)

def print_case(s, qs):
  res = '%s\n' % s
  res += '%d\n' % len(qs)
  res += ''.join([' '.join([str(x) for x in q]) + '\n' for q in qs])
  return res
  
def random_str(n, max_chars=6):
  chars = 'abcdef'
  chars = chars[:max_chars]
  return ''.join([random.choice(chars) for _ in range(n)])

def get_base_str(args):
  n = int(args['n'])
  max_chars = int(args['max_chars']) if 'max_chars' in args else 6
  if 'base_str' in args:
    b = args['base_str']
    s = b * ((n + len(b) - 1) // len(b))
    s = s[:n]
  else:
    s = random_str(n, max_chars)
  return s
  
def random_case(args):
  n = int(args['n'])
  q = int(args['q'])
  q_prob = float(args['q_prob'])
  min_qlen = int(args['min_qlen']) if 'min_qlen' in args else 1
  max_chars = int(args['max_chars']) if 'max_chars' in args else 6
  
  s = get_base_str(args)
  qs = []
  while len(qs) < q:
    if random.random() < q_prob:
      l, r = 0, -1
      while r - l + 1 < min_qlen:
        l, r = rand(1, n), rand(1, n)
        if l > r: l, r = r, l
      qs.append([1, l, r])
    else:
      ch = random_str(1, max_chars)
      qs.append([2, rand(1, n), ch])
  return print_case(s, qs)

def stairs(args):
  n = int(args['n'])
  q = int(args['q'])
  q_prob = float(args['q_prob'])
  max_chars = int(args['max_chars']) if 'max_chars' in args else 6
  s = get_base_str(args)
  qs = []
  i = 1
  while len(qs) < q:
    if random.random() < q_prob:
      if i + (n // 2) > n: i = 1
      l, r = i, i + (n // 2)
      qs.append([1, l, r])
      i += 1
    else:
      ch = random_str(1, max_chars)
      qs.append([2, rand(1, n), ch])
  return print_case(s, qs)

def long_queries(args):
  n = int(args['n'])
  q = int(args['q'])
  q_prob = float(args['q_prob'])
  max_chars = int(args['max_chars']) if 'max_chars' in args else 6
  s = get_base_str(args)
  qs = []
  i = 1
  while len(qs) < q:
    if random.random() < q_prob:
      l = rand(1, n // 10)
      r = rand(n - n // 10, n)
      qs.append([1, l, r])
    else:
      ch = random_str(1, max_chars)
      qs.append([2, rand(1, n), ch])
  return print_case(s, qs)
