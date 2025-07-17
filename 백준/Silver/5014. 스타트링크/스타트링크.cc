#include <iostream>
#include <queue>
using namespace std;
#define MAX 1000001

int f, s, g, u, d; 
queue<int> q;
bool visited[MAX];
int dist[MAX];
int calc();

int main() {
    cin >> f >> s >> g >> u >> d;
    int res = calc();
    cout << ((res == -1) ? "use the stairs" : to_string(res));
}

int calc() {
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == g) return dist[g];
        int up = cur + u;
        int down = cur - d;

        if (up <= f && !visited[up]) {
            dist[up] = dist[cur] + 1;
            visited[up] = true;
            q.push(up);
        }
        if (down > 0 && !visited[down]) {
            dist[down] = dist[cur] + 1;
            visited[down] = true;
            q.push(down);
        }
    }
    return -1;
}