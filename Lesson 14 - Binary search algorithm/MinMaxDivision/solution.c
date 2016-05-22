// Code written in C
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N*log(N+M))
// Space Complexity: O(1)

int check(int A[], int N, int K, int mid) {
    int sum = 0;
    int blocks = 0;

    for (int i = 0; i < N; ++i) {
        if ((sum + A[i]) > mid) {
            sum = A[i];

            if (++blocks >= K) {
                return 0;
            }

        } else {
            sum += A[i];
        }
    }

    return 1;
}

int solution(int K, int M, int A[], int N) {
    int min_sum = 0;
    int max_sum = 0;

    // Calculate sum of total array (max_sum)
    // and max value in array (min_sum)
    for (int i = 0; i < N; ++i) {
        max_sum += A[i];

        if (A[i] > min_sum) {
            min_sum = A[i];
        }
    }

    if (K == 1) {
        // Split only into 1 block so
        // return total sum
        return max_sum;
    } else if (K == N) {
        // Split into N many blocks
        // so return max value
        return min_sum;
    }

    int mid;

    while (min_sum <= max_sum) {
        mid = (min_sum + max_sum) / 2;

        if (check(A, N, K, mid)) {
            max_sum = mid - 1;
        } else {
            min_sum = mid + 1;
        }
    }

    return min_sum;
}
