#!/usr/bin/env python3

import string
import random

target = 1518
sum = 0
key = ''

avg = (target // ord('a')) + 1

while sum != target:
    while len(key) < avg:
        letter = random.choice(string.ascii_letters + string.digits)
        key += letter
        sum += ord(letter)
    if sum != target:
        print(key, target, sum, sum+ord(letter), end='\r')
        sum = 0
        key = ''

print(key, target, sum, '                      ')
