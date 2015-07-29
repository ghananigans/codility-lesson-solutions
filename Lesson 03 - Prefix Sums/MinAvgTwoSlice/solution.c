// Code written in C
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N)
// Space Complexity: O(1) 

double min(double a, double b) {
    return (a < b) ? a : b;
}

int solution(int A[], int N) {
    double minV = (A[0] + A[1]) / 2.0;
    int minP = 0;

    for (int i = 0; i < N-2; i++) {
        double tempMinV = min((A[i] + A[i + 1]) / 2.0, (A[i] + A[i + 1] + A[i + 2]) / 3.0);

        if (tempMinV < minV) {
            minV = tempMinV;
            minP = i;
        }
    }

    if (((A[N - 2] + A[N - 1]) / 2.0) < minV) {
        minP = N - 2;
    }

    return minP;
}
