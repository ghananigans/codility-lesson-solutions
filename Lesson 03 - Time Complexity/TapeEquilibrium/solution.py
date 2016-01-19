#Code written in Python
#Correctness: 100 %
#Performance: 100 %
#Time Complexity: O(N)
#Space Complexity: O(1)

def solution(A):
    sumLeft = A[0]
    sumRight = sum(A[1:])
    difference = abs(sumLeft - sumRight)

    for i in range (1, len(A) - 1):
        sumLeft += A[i]
        sumRight -= A[i]
        tempDifference = abs(sumLeft - sumRight)

        if (tempDifference < difference):
            difference = tempDifference

        i = i + 1

    return difference
