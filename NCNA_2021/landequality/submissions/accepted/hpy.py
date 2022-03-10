#!python3
from collections import Counter

n, m = map(int,input().split(" "))
c=Counter()
first_col=[]
for i in range(0,n):
    vec = list(map(int,input().split(" ")))    
    first_col.append(vec[0])
    c+=Counter(vec)

if(c[0]>=2):
    print(0)
elif(c[0]==1):
  if(n==1 or m==1):
    temp_vec= vec if n==1 else first_col
    if(temp_vec[0]==0):
      print(temp_vec[-1])
    elif(temp_vec[-1]==0):
      print(temp_vec[0])
    else:
      print(min(temp_vec[0],temp_vec[-1]))
  else:
    if(c[1]>0):
        print(1)
    else:
        print(2)

elif(c[2]%2==0):
    print(0)
else:
    print(2**(c[2]//2))
