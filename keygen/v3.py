#!/usr/bin/env python3

import string
import random

max_length = 27
blocks = 4
block_size = 6
target = 1801
sum = 0
key = ''

avg = (target // ord('a')) + 1

while sum != target:
    while len(key) < blocks * block_size:
        letter = random.choice(string.ascii_letters + string.digits)
        key += letter
        sum += ord(letter)
    if sum != target:
        print(key, target, sum, sum+ord(letter), end='\r')
        sum = 0
        key = ''

for x in range(0, blocks-1):
    key = key[:block_size*(x+1)+x] + '-' + key[block_size*(x+1)+x:]

print(key, target, sum, '                      ')
