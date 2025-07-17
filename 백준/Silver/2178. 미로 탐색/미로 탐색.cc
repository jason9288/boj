#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define MAX 101

int n, m;
int maze[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

queue< pair<int, int> > q;

void bfs(int x, int y) {
    visited[x][y] = true;
    q.push({x, y});
    dist[x][y]++;

    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = cur_x + dx[i];
            int new_y = cur_y + dy[i];

            if ((new_x >= 0 && new_x < n) && (new_y >= 0 && new_y < m) && visited[new_x][new_y] == false && maze[new_x][new_y] == 1) {
                visited[new_x][new_y] = true;
                q.push({new_x, new_y});
                dist[new_x][new_y] = dist[cur_x][cur_y] + 1;
            }
        }
    }
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            maze[i][j] = row[j] - '0';
        }
    }

    bfs(0, 0);

    cout << dist[n-1][m-1];
}