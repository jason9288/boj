#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v;
vector<bool> isVisited_dfs;
vector<bool> isVisited_bfs;
vector<vector<int>> graph;


void input() {
    cin >> n >> m >> v;

    isVisited_dfs.assign(n+1, false);
    isVisited_bfs.assign(n+1, false);
    graph.assign(n+1, vector<int> ());

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].emplace_back(e);
        graph[e].emplace_back(s);
    }
}

void dfs(int cur) {
    isVisited_dfs[cur] = true;
    cout << cur << " ";

    for (int i = 0; i < graph[cur].size(); i++) {
        int next = graph[cur][i];
        if (!isVisited_dfs[next]) {
            dfs(next);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    isVisited_bfs[start] = true;

    while (!q.empty()) { 
        int cur = q.front();
        q.pop(); // 가장 앞 요소 제거
        cout << cur << ' ';

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (!isVisited_bfs[next]) {
                q.push(next);
                isVisited_bfs[next] = true;
            }
        }
    }
}

int main() {
    input();
    
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(v);
    cout << '\n';
    bfs(v);
}