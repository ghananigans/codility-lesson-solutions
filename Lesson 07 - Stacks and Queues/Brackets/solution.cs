// Code written in C#
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N)
// Space Complexity: O(N)

using System;
using System.Collections.Generic;

class Solution {
    public int solution(string S) {
        int N = S.Length;
        
        Stack<char> stack = new Stack<char>();
        
        for (int i = 0; i < N; i++) {
            if ((S[i] == '(') || (S[i] == '{') || (S[i] == '[')) {
                stack.Push(S[i]);
            } else {
                if (stack.Count == 0) {
                    return 0;
                }
                
                char peek = stack.Peek();
                
                if (((peek == '(') && (S[i] == ')')) || ((peek == '{') && (S[i] == '}')) || ((peek == '[') && (S[i] == ']'))) {
                    stack.Pop();
                } else {
                    return 0;
                }
            }
        }
        
        return (stack.Count == 0) ? 1 : 0;
    }
}
