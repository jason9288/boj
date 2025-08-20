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

vector<vector<int>> g;

int main() {
    FAST_IO

    int n,m; cin >> n >> m;

    g.assign(n+1, vector<int>(m+1, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int k; cin >> k;
            g[i][j] = k;
        }
    }


    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] > 0) {
                int tmp = g[i][j];
                for (int k = j; k < m; k++) {
                    if (g[i][k] == 0) break;
                    if (g[i][k] == tmp) g[i][k] = 0;
                }
                cnt++;
            }
        }
    }

    cout << cnt;
}   