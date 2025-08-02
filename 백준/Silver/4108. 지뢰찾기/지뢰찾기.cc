#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[8] = {0, 0, -1, 1, 1, -1, -1, 1};

int main() {
    while (true) {
        int r, c; cin >> r >> c;
        if (r == 0 && c == 0) break;
    
        vector<string> m;
        for (int i = 0; i < r; i++) {
            string s; cin >> s;
            m.push_back(s);
        }
    
        vector<vector<int>> ans;
        ans.assign(r, vector<int>(c, -1));
    
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (m[i][j] == '.') {
                    int sum = 0;
                    for (int k = 0; k < 8; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
                        if (m[nx][ny] == '*') sum++;
                    }
                    ans[i][j] = sum;
                }
            }
        }
    
        for (const auto& v : ans) {
            for (int i : v) {
                if (i == -1) {
                    cout << '*';
                } else {
                    cout << i;
                }
            }
            cout << '\n';
        }
    }
}