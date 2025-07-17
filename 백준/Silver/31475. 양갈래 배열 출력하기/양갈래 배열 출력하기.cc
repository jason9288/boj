#include <iostream>
#include <vector>
using namespace std;

int n, m;

void sol(int row, int col, string prev_dir, int depth, vector<vector<int>>& arr, vector<vector<bool>>& visited) {
    if (!visited[row][col]) {
        arr[row][col] = depth;
        visited[row][col] = true;
    } else {
        return;
    }
    if (prev_dir == "down") {
        if (row+1 >= n || visited[row+1][col]) {
            if (col-1 >= 0) {
                sol(row, col-1, "left", depth+1, arr, visited);
            }
            if (col+1 < m) {
                sol(row, col+1, "right", depth+1, arr, visited);
            }
        } else {
            sol(row+1, col, "down", depth+1, arr, visited);
        }
    } else if (prev_dir == "up") {
        if (row-1 < 0 || visited[row-1][col]) {
            if (col-1 >= 0) {
                sol(row, col-1, "left", depth+1, arr, visited);
            }
            if (col+1 < m) {
                sol(row, col+1, "right", depth+1, arr, visited);
            }
        } else {
            sol(row-1, col, "up", depth+1, arr, visited);
        }
    } else if (prev_dir == "left") {
        if (col-1 < 0 || visited[row][col-1]) {
            if (row-1 >= 0) {
                sol(row-1, col, "up", depth+1, arr, visited);
            } 
            if (row+1 < n) {
                sol(row+1, col, "down", depth+1, arr, visited);
            }
        } else {
            sol(row, col-1, "left", depth+1, arr, visited);
        }
    } else { // right
        if (col+1 >= m || visited[row][col+1]) {
            if (row-1 >= 0) {
                sol(row-1, col, "up", depth+1, arr, visited);
            } 
            if (row+1 < n) {
                sol(row+1, col, "down", depth+1, arr, visited);
            }
        } else {
            sol(row, col+1, "right", depth+1, arr, visited);
        }
    }
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    char c;
    cin >> c;

    vector<vector<int>> arr(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int s_row, s_col;
    switch(c) {
        case 'U':
            s_row = 0; s_col = (m-1)/2;
            sol(s_row, s_col, "down", 1, arr, visited);
            break;
        case 'D':
            s_row = n-1; s_col = (m-1)/2;
            sol(s_row, s_col, "up", 1, arr, visited);
            break;
        case 'L':
            s_row = (n-1)/2; s_col = 0;
            sol(s_row, s_col, "right", 1, arr, visited);
            break;
        case 'R':
            s_row = (n-1)/2; s_col = m-1;
            sol(s_row, s_col, "left", 1, arr, visited);
            break;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}