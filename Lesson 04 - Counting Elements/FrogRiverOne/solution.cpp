// Code written in C++
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N)
// Space Complexity: O(X)


int solution(int X, vector<int> &A) {
    bool landed[X];

    for (int i = 0; i < X; i++) {
        landed[i] = false;
    }

    for(int i = 0; i < A.size(); i++) {
        if (!landed[A[i] - 1]) {
            landed[A[i] - 1] = true;

            if (--X == 0) {
                return i;
            }
        }
    }

    return -1;
}
