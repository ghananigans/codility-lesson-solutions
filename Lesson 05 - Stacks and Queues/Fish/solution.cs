// Code written in C#
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N)
// Space Complexity: O(N)

using System;
using System.Collections.Generic;

class Solution {
    public int solution(int[] A, int[] B) {
        int N = A.Length;

        Stack<int> upStream = new Stack<int>();
        Stack<int> downStream = new Stack<int>();
        
        for (int i = 0; i < N; i++) {
            if ((B[i] == 0)) {            
                upStream.Push(A[i]);
                
                while (downStream.Count > 0) {
                    if (downStream.Peek() < A[i]) {
                        downStream.Pop();
                    } else {
                        upStream.Pop();
                        break;
                    }
                }
            } else {
                downStream.Push(A[i]);
            }
        }
        
        return downStream.Count + upStream.Count;
    }
}
