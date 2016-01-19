// Code written in C
// Correctness: 100 %
// Performance: Not assessed
// Time Complexity: O(N)
// Space Complexity: O(N)

struct Results solution(int A[], int N, int K) {
    struct Results result;
    result.N = N;
    
    if (N == 0) {
        result.A = A; 
    } else {
        K = K % N;
    
        int *retA = (int *)malloc(N * sizeof(int));
    
        for (int i = 0; i < N; ++i) {
            int a = (i + K) % N;
            retA[a] = A[i];
        }
        
        result.A = retA;
    }

    return result;
}
