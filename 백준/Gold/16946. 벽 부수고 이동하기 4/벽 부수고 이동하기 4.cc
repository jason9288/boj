#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
constexpr bool ndebug = true;
#else
constexpr bool ndebug = false;
#endif
#define FAST_IO \
    if constexpr (ndebug) { cin.tie(nullptr); ios::sync_with_stdio(false); }
#define debug(x) \
    if constexpr (!ndebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugf(...) \
    if constexpr (!ndebug) { cout << "[DEBUG] "; printf(__VA_ARGS__); }
#define debugc(c) \
    if constexpr (!ndebug) { cout << "[DEBUG] " << #c << ": "; for (const auto& elem : c) cout << elem << " "; cout << '\n'; }
//=========================================================================================================

struct Point {
    int isWall, spaces, visited, groupid;
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<vector<Point>> M;

int n, m;
int s_cnt = 1;
int gid = 1;

void dfs(int x, int y, vector<pair<int, int>>& g_cnt) {
    M[x][y].visited = 1;
    g_cnt.push_back({x, y});
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
            if (M[nx][ny].isWall == 0 && M[nx][ny].visited == 0) {
                dfs(nx, ny, g_cnt);
                s_cnt++;
            }
        }
    }
}

int main() {
    FAST_IO

    cin >> n >> m;
    M.assign(n, vector<Point>(m, {0, 0, 0, -1}));
    for (int i = 0; i < n; i++) {
        string in; cin >> in;
        for (int j = 0; j < m; j++) {
            int c = in[j] - '0';
            M[i][j].isWall = c;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (M[i][j].isWall == 0 && M[i][j].visited == 0 && M[i][j].spaces == 0) {
                s_cnt = 1;
                vector<pair<int, int>> groupcnt;
                dfs(i, j, groupcnt);
                for (auto [x, y] : groupcnt) {
                    M[x][y].spaces = s_cnt;
                    M[x][y].groupid = gid;
                }
                gid++;
            }
        }
    }


    vector<vector<int>> answer(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (M[i][j].isWall == 0) continue;
            int sum = 1;
            unordered_set<int> s;

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    if (s.count(M[nx][ny].groupid)) continue;
                    if (M[nx][ny].isWall == 0) {
                        sum += M[nx][ny].spaces;
                        s.insert(M[nx][ny].groupid);
                    }
                }
            }
            answer[i][j] = sum % 10;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << answer[i][j];
        }
        cout << '\n';
    }
}