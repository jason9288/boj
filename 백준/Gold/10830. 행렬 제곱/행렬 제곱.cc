#include <iostream>
#include <vector>
#include <cmath>
typedef unsigned long long ull;
using namespace std;
    
// dp[0] = A, dp[1] = A^2, dp[2] = A^4...
vector<vector<vector<ull>>> Apow2;
int n;

vector<vector<ull>> matrix_multi(vector<vector<ull>>& A, vector<vector<ull>>& B) {
    vector<vector<ull>> C;
    for (int i = 0; i < n; i++) {
        vector<ull> row(n, 0);
        C.push_back(row);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ull val = (A[i][k] * B[k][j]);
                C[i][j] += val;
            }
            C[i][j] %= 1000;
        }
    }
    return C;
}

void dp_initial(vector<vector<ull>>& A) {
    for (int i = 1; i <= 36; i++) {
        Apow2.push_back(matrix_multi(Apow2[i-1], Apow2[i-1]));
    }
}

int getMax2Pow(ull target) {
    int i = 0;
    ull p = 1;
    while (p <= target) {
        p <<= 1;
        i++;
    }
    return i-1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ull b;
    cin >> n >> b;

    vector<vector<ull>> A;
    for (int i = 0; i < n; i++) {
        vector<ull> row;
        for (int j = 0; j < n; j++) {
            ull num; cin >> num;
            row.push_back(num);
        }
        A.push_back(row);
    }

    if (b == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << A[i][j] % 1000 << " ";
            }
            cout << endl;
        }
        return 0;
    }

    Apow2.push_back(A);
    dp_initial(A);

    ull temp_b = b;
    vector<vector<ull>> M(n, vector<ull>(n, 0));
    for (int i = 0; i < n; i++) {
        M[i][i] = 1; 
    }

    if (temp_b != 0) {
        while (true) {
            if (temp_b == 0) break;
            int maxI = getMax2Pow(temp_b);
            M = matrix_multi(Apow2[maxI], M);
            temp_b -= (1ULL << maxI);
        } 
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << M[i][j] % 1000 << " ";
        }
        cout << endl;
    }
}