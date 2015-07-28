// Code written in C++
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N)
// Space Complexity: O(N)

int solution(vector<int> &A) {
    unsigned int N = A.size();
    
    bool checked[N];
    
    for (int i = 0; i < N; i++) {
        checked[i] = false;
    }
    
    for (std::vector<int>::iterator it = A.begin(); it != A.end(); it++) {
        if (*it > N) { return 0; }
        else if (checked[*it - 1]) { return 0; }
        else { checked[*it - 1] = true; }
    }
    
    return 1;
}
