#!usr/bin/python3

import sys
import re

ln = sys.stdin.readline()
assert re.match('^[()\[\]{}<>?]+\n$', ln)
s = ln.rstrip('\n')

assert len(s) % 2 == 0
assert len(s) <= 20

assert '?' in s

sys.exit(42)
