# Code written in Python
# Correctness: 100 %
# Performance: 100 %
# Time Complexity: O(log(N + M))
# Space Complexity: O(log(N + M))

def solution(N, M):
    nm_gcd = gcd(N, M, 1)
    return N / nm_gcd

def gcd(a, b, res):
    if (a == b):
        return res * a
    elif (a % 2 == 0) and (b % 2 == 0):
        return gcd(a // 2, b // 2, res * 2)
    elif (a % 2 == 0):
        return gcd(a // 2, b, res)
    elif (b % 2 == 0):
        return gcd(a, b // 2, res)
    elif (a > b):
        return gcd(a - b, b, res)
    else:
        return gcd(a, b - a, res)
