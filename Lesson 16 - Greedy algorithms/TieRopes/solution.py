# Code written in Python
# Correctness: 100 %
# Performance: 100 %
# Time Complexity: O(N)
# Space Complexity: O(1)

def solution(K, A):
    N = len(A)
    ropes = 0

    if N == 1:
        return 1 if A[0] >= K else 0

    left = 0
    right = 0
    temp_sum = 0

    while right < N:
        temp_sum += A[right]

        if temp_sum >= K:
            ropes += 1
            left = right + 1
            right = left
            temp_sum = 0
        else:
            right += 1

    return ropes
