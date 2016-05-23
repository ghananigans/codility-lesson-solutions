# Code written in Python
# Correctness: 100 %
# Performance: 100 %
# Time Complexity: O(N)
# Space Complexity: O(N)

def solution(A):
    check = {}
    count = 0

    for n in A:
        key = abs(n)
        if key not in check:
            count += 1
            check[key] = True

    return count
