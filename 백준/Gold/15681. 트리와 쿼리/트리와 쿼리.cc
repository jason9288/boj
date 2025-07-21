#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001

vector<int> connect[MAX];
vector<int> tree[MAX];
int parent[MAX];

void makeTree(int cur, int par) {
    parent[cur] = par;
    for (int nxt : connect[cur]) {
        if (nxt != par) {
            tree[cur].push_back(nxt);
            makeTree(nxt, cur);
        }
    }
}

int subTreeCount[MAX];

void getCount(int cur) {
    subTreeCount[cur] = 1;
    for (int nxt : tree[cur]) {
        getCount(nxt);
        subTreeCount[cur] += subTreeCount[nxt];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, r, q;
    cin >> n >> r >> q;

    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        connect[u].push_back(v);
        connect[v].push_back(u);
    }

    makeTree(r, 0);
    getCount(r);

    for (int i = 0; i < q; i++) {
        int in; cin >> in;
        cout << subTreeCount[in] << "\n";
    }
}