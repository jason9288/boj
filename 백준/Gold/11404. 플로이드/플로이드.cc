#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// 플로이드-워셜
int n, m;

// 오버플로우 체크
int check_overflow(int n1, int n2) {
    if (n1 >= INT_MAX - n2) return INT_MAX;
    else return n1+n2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int table[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                table[i][j] = 0;
                continue;
            }    
            table[i][j] = INT_MAX;
        }
    }
    int from, to, cost;
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> cost;
        table[from-1][to-1] = min(table[from-1][to-1], cost);; 
    }
    for (int k = 0; k < n; k++) {
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                table[a][b] = min(table[a][b], check_overflow(table[a][k], table[k][b]));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] == INT_MAX) {
                cout << 0 << " ";
            } else {
                cout << table[i][j] << " ";
            }
        }
        cout << endl;
    }
}