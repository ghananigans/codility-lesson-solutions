// Code written in JavaScript
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N)
// Space Complexity: O(N)

function solution(A) {
    var N = A.length;
    
    if (N < 4) {
        return 0;    
    }

    var max_ending = new Array();
    var max_starting = new Array();
    
    max_ending[0] = 0;
    max_ending[N - 1] = 0;
    max_starting[0] = 0;
    max_starting[N - 1] = 0;
    
    var i = 0;
    
    for (i = 1; i < (N - 1); i++) {
        max_ending[i] = Math.max(0, max_ending[i - 1] + A[i]);
        max_starting[N - 1 - i] = Math.max(0, max_starting[N - i] + A[N - 1 - i]);
    }
    
    
    var max = 0;
    
    for (i = 1; i < (N - 1); i++) {
        max = Math.max(max, max_ending[i - 1]  + max_starting[i + 1]);
    }
    
    return max;
}
