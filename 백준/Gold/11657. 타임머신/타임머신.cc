#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX ~0U >> 2

struct edge {
    int s, e;
    long long t;
};

int n, m;
bool time_travel;

vector<long long> bellman_ford(int n, vector<edge> edges) {
    vector<long long> dist(n+1, MAX);

    int s, e, t;
    dist[1] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < edges.size(); j++) {
            s = edges[j].s;
            e = edges[j].e;
            t = edges[j].t;
            // 각 엣지에 대해 relax
            if (s != 1 && dist[s] == MAX) continue;
            if (dist[e] > dist[s] + t) {
                dist[e] = dist[s] + t;
            }
        }
    }
    for (int i = 0; i < edges.size(); i++) {
        s = edges[i].s;
        e = edges[i].e;
        t = edges[i].t;
        if (s != 1 && dist[s] == MAX) continue;
        if (dist[e] > dist[s] + t) {
            time_travel = true;
            return dist;
        }
    }
    time_travel = false;
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    
    int s, e, t;
    cin >> n >> m;
    vector<edge> edges;

    for (int i = 0; i < m; i++) {
        cin >> s >> e >> t;
        edges.push_back({s,e,t});
    }

    vector<long long> res = bellman_ford(n, edges);

    if (time_travel) {
        cout << "-1";
    } else {
        for (int i = 2; i < res.size(); i++) {
            if (res[i] == MAX) {
                cout << "-1" << endl;
                continue;
            } else { 
                cout << res[i] << endl;
            }
        }
    }
}