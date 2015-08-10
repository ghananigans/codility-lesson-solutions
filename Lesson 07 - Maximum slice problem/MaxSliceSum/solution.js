// Code written in JavaScript
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N)
// Space Complexity: O(1)

function solution(A) {
    var N = A.length;
    
    var max_slice = A[0];
    var max_ending = A[0];
    
    for (var i = 1; i < N; i++) {
        max_ending = Math.max(A[i], max_ending + A[i]);
        max_slice = Math.max(max_slice, max_ending);
    }
    
    return max_slice;
}}
