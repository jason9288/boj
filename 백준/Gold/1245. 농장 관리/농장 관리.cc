#include <iostream>
#include <vector>
using namespace std;

int n, m;
int cnt = 0;
bool bonguri;
vector<vector<int>> farm;
vector<vector<bool>> visited;
int drow[8] = {-1,0,1,1,1,0,-1,-1};
int dcol[8] = {1,1,1,0,-1,-1,-1,0};

bool isValid(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return false;
    return true;
}

void checkH(int row, int col, int depth) {

    visited[row][col] = true;
    int h = farm[row][col];

    for (int i = 0; i < 8; i++) {
        int nxt_r = row + drow[i];
        int nxt_c = col + dcol[i];
        if (!isValid(nxt_r, nxt_c)) {
            continue;
        }

        if (farm[nxt_r][nxt_c] > h) {
            bonguri = false;
        }
        if (farm[nxt_r][nxt_c] == h) {
            if (visited[nxt_r][nxt_c]) {
                continue;
            }
            checkH(nxt_r, nxt_c, depth+1);
        }
    }
    if (depth == 0 && bonguri) {
        cnt++;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    farm.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> farm[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j]) continue;
            if (farm[i][j] != 0) {
                bonguri = true;
                checkH(i, j, 0);
            }
        }
    }

    cout << cnt;
}