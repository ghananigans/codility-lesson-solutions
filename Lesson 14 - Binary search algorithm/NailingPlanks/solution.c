// Code written in C
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O((N+M)*log(M))
// Space Complexity: O(M)

int solution(int A[], int B[], int N, int C[], int M) {
    int min_nails = 1;
    int max_nails = M;
    int mid;
    int nails = -1;

    // Possible nail position is 2 * M
    int nailedCount = 2 * M + 1;
    int nailed[2 * M + 1];

    while (min_nails <= max_nails) {
        for (int i = 0; i < nailedCount; ++i) {
            nailed[i] = 0;
        }

        mid = (min_nails + max_nails) / 2;

        for (int i = 0; i < mid; ++i) {
            nailed[C[i]]++;
        }

        for (int i = 0; i < nailedCount; ++i) {
            nailed[i + 1] += nailed[i];
        }

        int missing = 0;
        for (int i = 0; i < N; ++i) {
            if (nailed[A[i] - 1] == nailed[B[i]]) {
                // No nail exists for board i
                missing = 1;
                break;
            }
        }

        if (missing) {
            min_nails = mid + 1;
        } else {
            max_nails = mid - 1;
            nails = mid;
        }
    }

    return nails;
}
