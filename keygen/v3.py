#!/usr/bin/env python3

# ; token length = 27
# 0x100000e5a      488b75f0       mov rsi, qword [local_10h]
# 0x100000e5e      488b7e08       mov rdi, qword [rsi + 8]
# 0x100000e62      8945dc         mov dword [local_24h], eax
# 0x100000e65      e8d8000000     call sym.imp.strlen        ; size_t strlen(const char *s)
# 0x100000e6a      4883f81b       cmp rax, 0x1b              ; 27
#
# ; 4 blocks with a separator between them
# 0x100000e9f      837de804       cmp dword [local_18h], 4
#
# ; one block contains 6 characters
# 0x100000eb0      837de406       cmp dword [local_1ch], 6
#
# ; sum of all the characters 0x709 (1081)
# 0x100000ef7      817dec090700.  cmp dword [local_14h], 0x709 ; [0x709:4]=-1 ; 1801
#
# XXXXXX XXXXXX XXXXXX XXXXXX
#
# ^^ easier to pass as an argument with non-space separator, let's choose '-'
# but can be anything else
#
# XXXXXX-XXXXXX-XXXXXX-XXXXXX
#
# Avg. block sum is 450.25
#
# 4 * 450 = 1080
#
# 450 / 6 = 75 ; 0x4b => 'K'
#
# we have to increase one of them: 'L'
#
# KKKKKK-KKKKKK-KKKKKK-KKKKKL
# 
# still valid keys (examples on separator):
# KKKKKKaKKKKKKaKKKKKKaKKKKKL
# KKKKKK/KKKKKK/KKKKKK/KKKKKL


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
