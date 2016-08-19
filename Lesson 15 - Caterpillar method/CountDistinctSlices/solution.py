# Code written in Python
# Correctness: 100 %
# Performance: 100 %
# Time Complexity: O(N)
# Space Complexity: O(M)

MAX_SLICES = 1000000000

def solution(M, A):
    N = len(A)
    a = 0
    b = 0
    count = 0
    countb = 0
    check = {}

    while a < N:
        while b < N and A[b] not in check:
            countb += 1
            check[A[b]] = True
            b += 1

        check.pop(A[a], None)

        a += 1
        count += countb
        countb -= 1

        if count >= MAX_SLICES:
                return MAX_SLICES

    return count
