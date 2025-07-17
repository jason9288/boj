#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, x, a, b, t;
const int INF = 1e9 + 7;
int dist_xton[1001];
vector<int> dist[2];
vector<pair<int, int>> g[2][1001];

void dijkstra(int dir) {
    dist[dir][x] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // w, node
    pq.push({0, x});

    while (!pq.empty()) {
        int d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (d > dist[dir][cur]) continue;

        for (int i = 0; i < g[dir][cur].size(); i++) {
            int nxt = g[dir][cur][i].second;
            int nxt_d = d + g[dir][cur][i].first;

            if (nxt_d < dist[dir][nxt]) {
                dist[dir][nxt] = nxt_d;
                pq.push({nxt_d, nxt});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill_n(dist_xton, 1001, INF);
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        g[0][a].push_back({t, b});
        g[1][b].push_back({t, a});
    }
    dist[0].resize(n+1, INF);
    dist[1].resize(n+1, INF);
    dijkstra(0);
    dijkstra(1);

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dist[0][i] + dist[1][i]);
    }
    cout << res;
}