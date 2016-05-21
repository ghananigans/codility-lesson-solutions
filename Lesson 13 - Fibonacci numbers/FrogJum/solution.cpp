// Code written in C++
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N*log(N))
// Space Complexity: O(N)

#include <vector>
#include <queue>
#include <iostream>

const int MAX_N_VALUE = 100000;

int solution(vector<int> &A) {
    const int N = A.size();

    // If only 1 or 2 leaves,
    // can jump that in 1 jump
    if (N < 3) {
        return 1;
    }
    
    // Generate fibonacci numbers
    std::vector<int> fibNums;
    fibNums.push_back(0);
    fibNums.push_back(1);
    
    for (int i = 2; fibNums.back() < MAX_N_VALUE; ++i) {
        fibNums.push_back(fibNums[i-1] + fibNums[i-2]);   
    }
    
    // Reachable leaves vector
    std::vector<int> reachable(N);
    for (int i = 0; i < N; ++i) {
        reachable[i] = 0;
    }

    int pos;
    
    // Queue of leaves positions to analyze, starting at -1
    std::queue<int> leavesToLookAt;
    leavesToLookAt.push(-1);
    
    // Get reachable leaves after first jump
    for (int i = 2; i < fibNums.size(); ++i) {
        pos = fibNums[i] - 1;
        
        if (pos > N) {
            break;
        } else if (pos == N) {
            return 1;
        } else if (A[pos]) {
             reachable[pos] = 1;
             leavesToLookAt.push(pos);
        }
    }
    
    // Look at humps from other leaves we have reached
    int nextPos;
    int minJumps = -1;
    
    while(leavesToLookAt.size()) {
        pos = leavesToLookAt.front();
        leavesToLookAt.pop();
        
        for (int i = 2; i < fibNums.size(); ++i) {
            nextPos = pos + fibNums[i];
            
            if (nextPos > N) {
                // can't jump more than N + 1 (destination)
                break;
            } else if (nextPos == N) {
                // Destination
                if ((minJumps == -1) || ((reachable[pos] + 1) < minJumps)) {
                    // Update minJumps if found a path that is cheaper
                    minJumps = reachable[pos] + 1;
                }
            } else if (A[nextPos] && !reachable[nextPos]) {
                reachable[nextPos] = reachable[pos] + 1;
                leavesToLookAt.push(nextPos);
            }
        }
    }

    return minJumps;
}

