#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int target;
    int dist;
};

int v; 
vector<vector<Edge>> graph;

int farthest_node;
int max_dist;

void dfs(int u, int parent, int cur_dist) {
    if (cur_dist > max_dist) {
        max_dist = cur_dist;
        farthest_node = u;
    }

    for (const auto& edge : graph[u]) {
        int neighbor = edge.target;
        if (neighbor != parent) {
            dfs(neighbor, u, cur_dist + edge.dist);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> v;
    graph.resize(v+1);

    for (int i = 0; i < v; i++) {
        int u;
        cin >> u;
        while (true) {
            int target, dist;
            cin >> target;
            if (target == -1) break;
            cin >> dist;
            graph[u].push_back({target, dist});
        }
    }

    max_dist = -1;
    farthest_node = 1;
    dfs(1, 0, 0);

    int start = farthest_node;
    max_dist = -1;
    dfs(start, 0, 0);

    cout << max_dist;
}