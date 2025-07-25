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

vector<int> r;
vector<int> g;
vector<int> b;
vector<int> paint;

int main() {
    FAST_IO

    int n; cin >> n;
    r.resize(n+1, 0);
    g.resize(n+1, 0);
    b.resize(n+1, 0);

    paint.resize(n+1, -1);
    for (int i = 1; i <= n; i++) {
        cin >> r[i] >> g[i] >> b[i];
    }

    vector<vector<int>> ans(n+1, vector<int>(3, ~0U >> 2));
    ans[0][0] = ans[0][1] = ans[0][2] = 0;

    int k = ~0U >> 2;

    for (int color = 0; color < 3; color++) {
        for (int i = 0; i < 3; i++) {
            if (i == color) {
                if (i == 0) ans[1][i] = r[1];
                if (i == 1) ans[1][i] = g[1];
                if (i == 2) ans[1][i] = b[1];
            }
            else { ans[1][i] = ~0U >> 2; }
        }
        for (int i = 2; i <= n; i++) {
            ans[i][0] = min(ans[i-1][1], ans[i-1][2]) + r[i];
            ans[i][1] = min(ans[i-1][0], ans[i-1][2]) + g[i];
            ans[i][2] = min(ans[i-1][0], ans[i-1][1]) + b[i];
        }
        for (int i = 0; i < 3; i++) {
            if (i == color) continue;
            k = min(k, ans[n][i]);
        }
    }
    

    cout << k;
}