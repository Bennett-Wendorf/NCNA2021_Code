import os

os.system('g++ -o bowen_map bowen_map.cpp -O2')
for input_file in os.listdir('./input'):
  if input_file.endswith('.in'):
    desc_file = input_file.replace('.in', '.desc')
    os.system('./bowen_map < input/%s > map/%s' % (input_file, desc_file))
  print (input_file)
os.remove('bowen_map')
