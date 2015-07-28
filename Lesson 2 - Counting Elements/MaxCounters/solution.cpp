// Code written in C++
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N + M)
// Space Complexity: O(N)

vector<int> solution(int N, vector<int> &A) {
    std::vector<int> *counter = new std::vector<int>(N);

    int max = 0;
    int setMax = 0;
    int M = A.size();

    for (int i = 0; i < M; i++) {
        if ((*counter)[A[i] - 1] < setMax) {
            (*counter)[A[i] - 1] = setMax;
        }
        
        if ((A[i] <= N) && (A[i] >= 0)) {
            if (++((*counter)[A[i] - 1]) > max) {
                max = (*counter)[A[i] - 1];
            }
        } else if (A[i] == (N + 1)) {
            setMax = max;
        }
    }

    for (int i = 0; i < N; i++) {
        if ((*counter)[i] < setMax) {
            (*counter)[i] = setMax;
        }
    }

    return *counter;
}
