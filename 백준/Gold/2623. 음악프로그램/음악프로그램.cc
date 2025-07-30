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
vector<int> ans;

bool t_sort(int n) {
    vector<int> indeg(n+1, 0);
    for (int u = 1; u <= n; u++) {
        for (int v : g[u]) indeg[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        for (int nxt : g[cur]) {
            if (--indeg[nxt] == 0) q.push(nxt);
        }
    }

    debugc(ans);

    if (ans.size() == n) {
        return true;
    } else {
        return false;
    }
}

int main() {
    FAST_IO

    int n, m; cin >> n >> m;
    g.resize(n+1);
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        vector<int> ns;
        for (int i = 0; i < k; i++) {
            int in; cin >> in;
            ns.push_back(in);
        }

        debugc(ns);

        if (ns.size() < 2) continue;

        for (int i = 0; i < ns.size()-1; i++) {
            g[ns[i]].push_back(ns[i+1]);
        }
    }

    if (!t_sort(n)) {
        cout << 0; 
        return 0;
    } else {
        for (int i = 0; i < n; i++) {
            cout << ans[i] << '\n';
        }
    }
}