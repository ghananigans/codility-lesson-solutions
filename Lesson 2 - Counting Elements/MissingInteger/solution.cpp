// Code written in C++
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <algorithm>

int solution(vector<int> &A) {
    std::sort(A.begin(), A.end());

    int N = A.size();

    if (A[N - 1] <= 0) { 
        return 1; 
    }

    if (A[0] > 1) {
        return 1;
    }

    for (int i = 0; i < (N - 1); i++) {
        if (A[i] <= 0) {
            if (A[i + 1] > 1) { 
                return 1; 
            }

            continue;
        }

        if ((A[i + 1] - A[i]) > 1) {
            return (A[i] + 1);
        }
    }

    return A[N-1] + 1;
}
