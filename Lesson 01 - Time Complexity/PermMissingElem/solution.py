#Code written in Python
#Correctness: 100 %
#Performance: 100 %
#Time Complexity: O(N)
#Space Complexity: O(1)

def solution(A):
    N = len(A) + 1
    missing = ((N + 1) * N) / 2
    
    for x in A:
        missing -= x
    
    return missing
