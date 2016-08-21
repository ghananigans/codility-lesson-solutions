# Code written in Python
# Correctness: 100 %
# Performance: 100 %
# Time Complexity: O(N^2)
# Space Complexity: O(N)

def solution(A):
    N = len(A)

    if N < 3:
        # Less than 3 sides so no triangles can be made
        return 0

    A.sort()
    num_triangles = 0

    for left in xrange(0, N - 2):
        right = left + 2

        for mid in xrange(left + 1, N - 1):
            while right < N and A[left] + A[mid] > A[right]:
                # Number of mid sides between mid and right is
                # valid since array is sorted.
                num_triangles += right - mid
                right += 1

    return num_triangles
