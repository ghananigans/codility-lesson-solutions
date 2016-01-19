// Code written in C++
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N + M)
// Space Complexity: O(N)

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    const int NUCLEOTIDES_TO_USE = 3;
    const int N = S.length();
    const int M = P.size();
    
    int **dna = new int*[NUCLEOTIDES_TO_USE];
    
    for (int i = 0; i < NUCLEOTIDES_TO_USE; i++) {
        dna[i] = new int[N + 1];
        dna[i][0] = 0;
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < NUCLEOTIDES_TO_USE; j++) {
            dna[j][i] = dna[j][i - 1];
        }

        switch (S[i - 1]) {
            case 'A':
                dna[0][i]++;
                break;
            case 'C':
                dna[1][i]++;
                break;
            case 'G':
                dna[2][i]++;
                break;
            default:
                break;
        }
    }
    
    std::vector<int> *results = new std::vector<int>(M);
    
    for (int i = 0; i < M; i++) {
        (*results)[i] = 4;
        
        for (int j = 0; j < NUCLEOTIDES_TO_USE; j++) {
            if ((dna[j][Q[i] + 1] - dna[j][P[i]]) > 0) {
                (*results)[i] = j + 1;
                break;
            }
        }
    }
    
    for (int j = 0; j < NUCLEOTIDES_TO_USE; j++) {
        delete[] dna[j];
    }
    delete[] dna;
    
    return *results;
}
