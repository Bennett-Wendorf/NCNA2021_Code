#!/usr/bin python3
import sys

DEBUG = False

rep = {'0':"....", '1':"...*", '2':"..*.", '3':"..**", '4':".*..", 
       '5':".*.*", '6':".**.", '7':".***", '8':"*...", '9':"*..*"}

def abend(mess):
  print(mess)
  exit(1)

input = sys.stdin.readline()
tnum = input.rstrip('\n')
if len(tnum) != 4: abend('bad input: ' + tnum)
try:
  n = int(tnum)
except ValueError as e:
  abend('bad input: ' + tnum)

ans = []
for d in tnum:
  ans.append(rep[d])

if DEBUG:
  print(ans)
  
for row in range(0,4):
  print(ans[0][row]+' '+ans[1][row]+'   '+ans[2][row]+' '+ans[3][row])
