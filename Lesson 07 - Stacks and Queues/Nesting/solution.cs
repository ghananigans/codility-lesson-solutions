// Code written in C#
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N)
// Space Complexity: O(1)

using System;

class Solution {
    public int solution(string S) {
        int N = S.Length;
        int counter = 0;
        
        for (int i = 0; i < N; i++) {
            if (S[i] == '(') {
                counter++;
            } else if (S[i] == ')') {
                if (--counter < 0) {
                    return 0;
                }
            }
        }
        
        return ((counter == 0) ? 1 : 0);
    }
}
