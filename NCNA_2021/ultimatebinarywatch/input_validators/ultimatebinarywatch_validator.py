#!/usr/bin python3
import sys
import re

ln = sys.stdin.readline()

assert re.match('^[0-9]{4}\n$', ln)

hh = int(ln[:2])
mm = int(ln[2:4])
  
assert 0 <= hh <= 23
assert 0 <= mm <= 59

sys.exit(42)
