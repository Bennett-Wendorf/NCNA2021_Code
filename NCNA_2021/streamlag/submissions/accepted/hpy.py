#!python3
from collections import Counter

n=int(input())

vec=[0 for i in range(0,n+1)]

for _ in range(0,n):
  ti,i = map(int,input().split(" "))
  vec[i]=ti

current_time=1
wait_time=0

for i in range(1,n+1):
  if vec[i]>current_time:
    wait_time+=vec[i]-current_time;
    current_time=vec[i]+1
  else:
    current_time+=1

print(wait_time)

