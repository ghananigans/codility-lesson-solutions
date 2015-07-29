// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    int N = S.length();
    int M = P.size();
    
    int *A = new int[N];
    int *C = new int[N];
    int *G = new int[N];

    A[0] = 0;
    C[0] = 0;
    G[0] = 0;

    switch (S[0]) {
        case 'A':
            A[0] = 1;
            break;
        case 'C':
            C[0] = 1;
            break;
        case 'G':
            G[0] = 1;
            break;
    }

    for (int i = 1; i < N; i++) {
        A[i] = A[i-1];
        C[i] = C[i-1];
        G[i] = G[i-1];

        switch (S[i]) {
            case 'A':
                A[i]++;
                break;
            case 'C':
                C[i]++;
                break;
            case 'G':
                G[i]++;
                break;
        }
    }

    std::vector<int> *result = new std::vector<int>(M);

    for (int i = 0; i < M; i++) {
        if (P[i] > 0) {
            if ((A[Q[i]] - A[P[i] - 1]) > 0) {
                (*result)[i] = 1;
            } else if ((C[Q[i]] - C[P[i] - 1]) > 0) {
                (*result)[i] = 2;
            } else if ((G[Q[i]] - G[P[i] - 1]) > 0) {
                (*result)[i] = 3;
            } else {
                (*result)[i] = 4;
            }
        } else {
            if ((A[Q[i]]) > 0) {
                (*result)[i] = 1;
            } else if ((C[Q[i]]) > 0) {
                (*result)[i] = 2;
            } else if ((G[Q[i]]) > 0) {
                (*result)[i] = 3;
            } else {
                (*result)[i] = 4;
            }
        }
    }

    delete[] A;
    delete[] C;
    delete[] G;

    return *result;
}
