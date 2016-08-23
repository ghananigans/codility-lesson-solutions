# Code written in Python
# Correctness: 100 %
# Performance: 100 %
# Time Complexity: O(N*log(N))
# Space Complexity: O(N)

def solution(A):
    N = len(A)

    if N == 1:
        return abs(A[0] * 2)

    A.sort()

    front = 0
    back = N - 1
    min_sum = abs(A[front] + A[back])

    while front < back:
        new_front = front + 1
        new_back = back - 1

        # New abs sum when front ptr is shifted to the right
        new_val_front = abs(A[new_front] + A[back])

        # New abs sum when back ptr is shifted to the left
        new_val_back = abs(A[front] + A[new_back])

        if new_val_front < new_val_back:
            # Shifting front ptr is better
            min_sum = min(new_val_front, min_sum)
            front = new_front
        else:
            # Shifting back ptr is better
            min_sum = min(new_val_back, min_sum)
            back = new_back

    return min_sum
