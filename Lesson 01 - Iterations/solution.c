// Code written in C
// Correctness: 100 %
// Performance: Not assessed
// Time Complexity: O(log(N))
// Space Complexity: O(1)

int solution(int N) {
    int longestBinaryGap = 0;
    int currentBinaryGap = -1;
    
    int val = N;
    
    while (val != 0) {
        if ((val & 1) == 1) {
            if (longestBinaryGap < currentBinaryGap) {
                longestBinaryGap = currentBinaryGap;
            }
            
            currentBinaryGap = 0;
        } else if (currentBinaryGap != -1) {
            ++currentBinaryGap;
        }
        
        val = val >> 1;
    }
    
    return longestBinaryGap;
}
