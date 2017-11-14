#!/bin/python3

import sys

def anagram(s):
    # Complete this function
    first = ""
    second = ""
    first_d = {}
    second_d = {}
    length_s = len(s)
    if length_s % 2 != 0:
        return -1
    else: 
        first, second = s[:len(s)//2], s[len(s)//2:]
      
        for c in first:
            if c not in first_d:
                first_d[c] = 1
            else:
                first_d[c] += 1
                
        for d in second:
            if d not in second_d:
                second_d[d] = 1
            else:
                second_d[d] += 1
        change = 0

        for c2 in second_d: 
            if (c2 in first_d):
                if(first_d[c2] == second_d[c2]):
                    continue
                elif(first_d[c2] != second_d[c2]):
                    change += abs(second_d[c2] - first_d[c2])
            elif(c2 not in first_d):
                change += second_d[c2]
        return change
           
q = int(input().strip())
for a0 in range(q):
    s = input().strip()
    result = anagram(s)
    print(result)