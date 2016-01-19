#Code written in Python
#Correctness: 100 %
#Performance: 100 %
#Time Complexity: O(1)
#Space Complexity: O(1)

import math

def solution(X, Y, D):
    jumps = int(math.ceil( float(Y-X)/D ))
    return jumps
