// Code written in C
// I used this task as an opportunity to play around with pointers a bit, explaining the confusing math with the pointers.
// There is C++ equivalent of this code available in solution.cpp
// Correctness: 100 %
// Performance: 100 %
// Time Complexity: O(N + M)
// Space Complexity: O(N)

struct Results solution(char *S, int P[], int Q[], int M) {
    const int NUCLEOTIDES_TO_USE = 3;
    const int N = strlen(S);

    int **dna = (int **)malloc(NUCLEOTIDES_TO_USE * sizeof(int *));

    for (int j = 0; j < NUCLEOTIDES_TO_USE; j++) {
        *(dna + j) = (int *)malloc((N + 1) * sizeof(int)); // dna[j]
        *(*(dna + j) + 0) = 0; // dna[j][0]
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < NUCLEOTIDES_TO_USE; j++) {
            *(*(dna + j) + i) = *(*(dna + j) + i - 1); // dna[j][i] = dna[j][i - 1]
        }

        switch (S[i - 1]) {
            case 'A':
                (*(*(dna + 0) + i))++; // dna[0][i]++
                break;
            case 'C':
                (*(*(dna + 1) + i))++; // dna[1][i]++
                break;
            case 'G':
                (*(*(dna + 2) + i))++; // dna[2][i]++
                break;
            default:
                break;
        }
    }

    int *resultA = malloc(M * sizeof(int));

    for (int i = 0; i < M; i++) {
        *(resultA + i) = 4; // resultA[i] = 4

        for (int j = 0; j < NUCLEOTIDES_TO_USE; j++) {
            if ((*(*(dna + j) +  *(Q + i) + 1) - *(*(dna + j) + *(P + i))) > 0) { // dna[j][Q[i] + 1] - dna[j][P[i]]
                *(resultA + i) = j + 1;
                break;
            }
        }
    }

    for (int j = 0; j < NUCLEOTIDES_TO_USE; j++) {
        free(dna[j]);
    }
    free(dna);

    struct Results result;
    result.A = resultA;
    result.M = M;

    return result;
}

