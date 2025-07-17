#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX ~0U >> 2

struct edge {
    int s, e, t;
};

int n, m, w;

bool neg_cycle(int n, vector<edge> edges) {
    vector<int> dist(n+1, MAX);

    int s, e, t;
    dist[1] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < edges.size(); j++) {
            s = edges[j].s;
            e = edges[j].e;
            t = edges[j].t;
            // 각 엣지에 대해 relax
            if (dist[e] > dist[s] + t) {
                dist[e] = dist[s] + t;
            }
        }
    }
    for (int i = 0; i < edges.size(); i++) {
        s = edges[i].s;
        e = edges[i].e;
        t = edges[i].t;
        if (dist[e] > dist[s] + t) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc;
    cin >> tc;

    int s, e, t;
    while (tc--) {
        cin >> n >> m >> w;
        vector<edge> edges;

        for (int i = 0; i < m; i++) {
            cin >> s >> e >> t;
            edges.push_back({s,e,t});
            edges.push_back({e,s,t});
        }
        for (int i = 0; i < w; i++) {
            cin >> s >> e >> t;
            edges.push_back({s,e,-t});
        }

        if (neg_cycle(n, edges)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}