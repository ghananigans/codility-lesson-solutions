// Code written in C#
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N)
// Space Complexity: O(N)

using System;
using System.Collections.Generic;

class Solution {
    public int solution(int[] H) {
        int N = H.Length;
        
        Stack<int> stack = new Stack<int>();
        stack.Push(H[0]);
        
        int blocks = 1;
        
        for (int i = 1; i < N; i++) {
            int currentHeight = 0;
            
            if (stack.Count > 0) {
                currentHeight = stack.Peek();
            }
            
            if (currentHeight > H[i]) {
                stack.Pop();
                i--;
            } else if (currentHeight < H[i]) {
                stack.Push(H[i]);
                blocks++;
            }
        }
        
        return blocks;
    }
}
