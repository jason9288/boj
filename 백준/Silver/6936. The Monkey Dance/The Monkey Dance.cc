#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dfs(int start, int cur, bool visit[], int graph[], int cycle) {
    if (visit[cur] && cur == start) {
        return cycle;
    } else {
        visit[cur] = true;
        return dfs(start, graph[cur], visit, graph, cycle+1);
    }
} 

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a*b)/gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    int graph[101];
    bool visit[101];
    while (true) {
        cin >> n;
        int cnt = n;
        if (n == 0) break;

        memset(graph, 0, sizeof(graph));
        memset(visit, 0, sizeof(visit));
        queue<int> cycles;
        while (cnt--) {
            int i1, i2;
            cin >> i1 >> i2;
            graph[i1] = i2; 
        }

        for (int i = 1; i <= n; i++) {
            if (!visit[i]) {
                cycles.push(dfs(i, i, visit, graph, 0));
            }
        }

        if (cycles.size() > 2) {
            int a = cycles.front();
            cycles.pop();
            int b = cycles.front();
            cycles.pop();

            int l = lcm(a, b);
            while (cycles.size() > 0) {
                l = lcm(cycles.front(), l);
                cycles.pop();
            }
            cout << l << endl;
        } else if (cycles.size() == 2) {
            int a = cycles.front();
            cycles.pop();
            int b = cycles.front();
            cout << lcm(a, b) << endl;
        } else {
            cout << cycles.front() << endl;
        }
    }
}