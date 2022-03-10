#!/usr/bin python3

import sys

DEBUG = False
MAXPRIMES = 100000

def abend(mess):
  print(mess)
  exit(1)

primes = [2,3,5,7,11,13,17,19]
nextTry = 21

def isPrime(n):
  for i in range(0,len(primes)):
    this = primes[i]
#    print(i,n,this)
    if (n % this) == 0: return False
    if (this * this) > n: return True
  return True


while len(primes) < MAXPRIMES:
  if isPrime(nextTry):
    primes.append(nextTry)
#    print(nextTry,len(primes))
  nextTry += 2


input = sys.stdin.readline()

case = input.split()
lower = int(case[0])
if (lower < 1) or (lower > MAXPRIMES): abend("lower out of range")
upper = int(case[1])
if (upper < 1) or (upper > MAXPRIMES): abend("upper out of range")
  
target = sys.stdin.readline().rstrip('\n')

if DEBUG: print(lower, upper, target)

count = 0
for i in range(lower,upper+1):
  cur = str(primes[i-1])
  hit = cur.find(target)
  if hit >= 0:
    if DEBUG: print(i,cur, hit)
    count += 1 
print(count)
