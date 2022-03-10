import random

random.seed('ultimatebinarywatch')

def rand(a,b):
  return random.randint(a,b)
    
def print_case(ds):
  return ''.join([str(d) for d in ds]) + '\n'
