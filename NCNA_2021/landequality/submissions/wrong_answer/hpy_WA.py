#!python3

from collections import Counter


if __name__ == "__main__":
    n, m = map(int,input().split(" "))
    c=Counter()
    for i in range(0,n):
        vec = map(int,input().split(" "))
        c+=Counter(vec)

    if(c[0]>=2):
        print(0)
    elif(c[0]==1):
        if(c[1]>0):
            print(1)
        else:
            print(2)
    
    elif(c[2]%2==0):
        print(0)
    else:
        print(2**(c[2]//2))
    
    