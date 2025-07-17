#include <iostream>
#include <vector>
using namespace std;

int ans = 0;

void dfs(int n, int** matrix, int row, int col, int status) {
    if (row == n-1 && col == n-1) {
        ans++;
        return;
    }
    // 가로 상태일때 (0)
    if (status == 0) {
        if (row+1 < n && col+1 < n && (matrix[row+1][col+1] != 1 && matrix[row+1][col] != 1 && matrix[row][col+1] != 1)) {
            dfs(n, matrix, row+1, col+1, 1);
        }
        if (col+1 < n && matrix[row][col+1] != 1) {
            dfs(n, matrix, row, col+1, 0);
        }
    }
    // 대각선 상태 (1)
    if (status == 1) {
        if (row+1 < n && col+1 < n && (matrix[row+1][col+1] != 1 && matrix[row+1][col] != 1 && matrix[row][col+1] != 1)) {
            dfs(n, matrix, row+1, col+1, 1);
        }
        if (col+1 < n && matrix[row][col+1] != 1) {
            dfs(n, matrix, row, col+1, 0);
        }
        if (row+1 < n && matrix[row+1][col] != 1) {
            dfs(n, matrix, row+1, col, 2);
        }
    }
    // 세로 상태 (2)
    if (status == 2) {
        if (row+1 < n && col+1 < n && (matrix[row+1][col+1] != 1 && matrix[row+1][col] != 1 && matrix[row][col+1] != 1)) {
            dfs(n, matrix, row+1, col+1, 1);
        }
        if (row+1 < n && matrix[row+1][col] != 1) {
            dfs(n, matrix, row+1, col, 2);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    int** matrix = new int*[n];

    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    dfs(n, matrix, 0, 1, 0);

    if (matrix[n-1][n-1] == 1) {
        cout << "0";
    } else {
        cout << ans;
    }
}