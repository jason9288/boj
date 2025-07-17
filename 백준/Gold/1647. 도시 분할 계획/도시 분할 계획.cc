#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int next;
    int weight;
};

struct Compare {
    bool operator()(const Edge& x, const Edge& y) {
        return x.weight > y.weight;
    }
};

vector<vector<Edge>> graph;
vector<bool> visited;
long long ans = 0;
long long max_weight = -1;

void Prim() {
    priority_queue<Edge, vector<Edge>, Compare> pq;
    pq.push({1, 0});

    while (!pq.empty()) {
        int curNode = pq.top().next;
        int curWeight = pq.top().weight;
        pq.pop();

        if (visited[curNode]) continue;

        visited[curNode] = true;
        if (max_weight < curWeight) max_weight = curWeight;
        ans += curWeight;

        for (Edge i : graph[curNode]) {
            int nxtNode = i.next;
            int nxtWeight = i.weight;
            pq.push({nxtNode, nxtWeight});
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int V, E; cin >> V >> E;
    graph.resize(V+1, vector<Edge>());
    visited.resize(V+1, false);

    for (int i = 0; i < E; i++) {
        int from, to, w;
        cin >> from >> to >> w;
        graph[from].push_back({to, w});
        graph[to].push_back({from, w});
    }

    Prim();
    cout << ans-max_weight;
}