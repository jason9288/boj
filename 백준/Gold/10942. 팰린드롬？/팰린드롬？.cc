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

vector<int> arr;
int n, m;

int main() {
    FAST_IO

    cin >> n;
    arr.push_back(0);
    for (int i = 0; i < n; i++) {
        int in; cin >> in;
        arr.push_back(in);
    }


    vector<vector<int>> p(n+1, vector<int>(n+1, 9));

    for (int i = 1; i <= n; i++) {
        p[i][i] = 1;
        p[i][i+1] = (arr[i] == arr[i+1]) ? 1 : 0;
    }

    for (int i = n-1; i >= 1; i--) {
        for (int j = i+2; j <= n; j++) {
            if (arr[i] == arr[j] && p[i+1][j-1] == 1) {
                p[i][j] = 1;
            }
        }
    }

    cin >> m;

    while(m--) {
        int s, e; cin >> s >> e;
        cout << ((p[s][e] == 1) ? 1 : 0) << '\n';
    }
}