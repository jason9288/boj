#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define MAX 1001

int n, m;
int tomato[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

queue< pair<int, int> > q;

void bfs() {
    while (!q.empty()) {
        int cur_x = q.front().second;
        int cur_y = q.front().first;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = cur_x + dx[i];
            int new_y = cur_y + dy[i];

            if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n) { continue; }
            if (tomato[new_y][new_x] == 0 && visited[new_y][new_x] == false) {
                visited[new_y][new_x] = true;
                q.push({new_y, new_x});
                dist[new_y][new_x] = dist[cur_y][cur_x] + 1;
            }
        }
    }
}


int main() {
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tomato[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tomato[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tomato[i][j] == 0 && dist[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }

    int day = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (day < dist[i][j]) {
                day = dist[i][j];
            }
        }
    }

    cout << day;
}