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

vector<vector<int>> graph;
vector<int> buildtime;

int toposort(int n, int w) {
    vector<int> indeg(n+1, 0);
    vector<int> dp(n+1, 0);
    for (int u = 1; u <= n; u++) {
        for (int v : graph[u]) indeg[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            dp[i] = buildtime[i];
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : graph[cur]) {
            dp[nxt] = max(dp[nxt], dp[cur] + buildtime[nxt]);
            if (--indeg[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    return dp[w];
}

int main() {
    FAST_IO
    
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        graph.assign(n+1, vector<int>());
        buildtime.assign(n+1, 0);
        
        for (int i = 1; i <= n; i++) {
            int d; cin >> d;
            buildtime[i] = d;
        }
        
        for (int i = 0; i < k; i++) {
            int a, b; cin >> a >> b;
            graph[a].push_back(b);
        }

        int w; cin >> w; // target
        
        int ans = toposort(n, w);
        // cout << "ans : " <<
        
        cout << ans << endl;
    }
}