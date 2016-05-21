// Code written in C++
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(L)
// Space Complexity: O(L)

#include <iostream>
#include <vector>
#include <algorithm>

vector<int> solution(vector<int> &A, vector<int> &B) {
    const int L = A.size();
    
    // index a has # of ways to get to rung a + 1 (fibonacci sequence)
    std::vector<unsigned int> step;
    step.push_back(1); // only 1 way to get to first step
    step.push_back(2); // two ways to get to second step
    
    std::vector<int> answer;
    
    for (int i = 0; i < L; ++i) {
        // Fill missing step counts
        for (int a = step.size(); a < A[i]; ++a) {
            step.push_back(step[a - 1] + step[a - 2]);
        }
        
        answer.push_back(step[A[i] - 1] & ((1 << B[i]) - 1));
    }
    
    return answer;
}
