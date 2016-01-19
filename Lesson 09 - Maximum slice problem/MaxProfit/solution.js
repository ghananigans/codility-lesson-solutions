// Code written in JavaScript
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N)
// Space Complexity: O(1)

function solution(A) {
    var N = A.length;
   
    var max_profit = 0;
    var min = 200001;

    for (var i = 0; i < N; i++) {
        if (min > A[i]) {
            min = A[i];
        } else {
            max_profit = Math.max(max_profit, A[i] - min);
        }
    }
   
    return max_profit;
}
