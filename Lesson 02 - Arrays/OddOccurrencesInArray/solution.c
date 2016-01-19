// Code written in C
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N)
// Space Complexity: O(1)

int solution(int A[], int N) {
    int ret = 0;
    
    for (int i = 0; i < N; ++i) {
        ret = ret ^ A[i];
    }
    
    return ret;
}
