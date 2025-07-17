#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> visited;
vector<pair<int, int>> tree[10001];
void dfs(int cur, int val);
int maxV = -1;
int maxNode = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    visited.resize(n+1, 0);
    int p, c, w;

    for (int i = 0; i < n-1; i++) {
        cin >> p >> c >> w;
        tree[p].push_back(make_pair(c, w));
        tree[c].push_back(make_pair(p, w));
    }
    dfs(1, 0);
    visited.assign(n+1, 0);
    maxV = -1;
    dfs(maxNode, 0);
    cout << maxV << endl;
}

void dfs(int cur, int val) {
    visited[cur] = 1;
    
    if (maxV < val) { // 모든 재귀 호출 이후에 실행됨
        maxV = val;
        maxNode = cur;
    }
    for (int i = 0; i < tree[cur].size(); i++) {
        if (visited[tree[cur][i].first] == 1) 
            continue;
        dfs(tree[cur][i].first, val+tree[cur][i].second);
    }
}