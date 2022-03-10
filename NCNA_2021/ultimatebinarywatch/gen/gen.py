# Created by TestGen
# https://github.com/yubowenok/testgen

import sys
import os

# add testgen to system path, or include the path here
sys.path.append('../..')

from testgen import Problem
import funcs

# create a new problem instance with given id
prob = Problem('ultimatebinarywatch')

# copy from the manual cases in input_manual
prob.manualCases('input_manual')

# parse the test generator rules defined in the file "ultimatebinarywatch.rules",
# and generate tests via program using the rules
prob.programCases('ultimatebinarywatch.rules', funcs)

# Group the cases into smaller number of files
# to create multpile subtasks or be compatible with non single-case judges.
# Use this only if you need case packing.
prob.packCases('ultimatebinarywatch.groups')

# generate answers using sol.cpp as the judge's solution
prob.generateAnswers('../submissions/accepted/bowen.cpp')
os.remove('../submissions/accepted/bowen')
