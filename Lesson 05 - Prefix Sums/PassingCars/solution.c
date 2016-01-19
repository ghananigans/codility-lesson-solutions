// Code written in C
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N)
// Space Complexity: O(1)

int solution(int A[], int N) {
    unsigned int counter = 0;
    unsigned int multiplier = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] != 0) {
            counter += multiplier;
            
            if (counter > 1000000000) {
                return -1;
            }
        } else {
            multiplier++;
        }
    }
    
    return counter;
}
