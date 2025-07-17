#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MIN ~0U >> 2

struct state {
    int x, y, broken;
};

vector<vector<int>> map;
vector<vector<vector<int>>> dist;
int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1}; 

void bfs() {
    queue<state> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;

    while (!q.empty()) {
        state cur = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int new_x = cur.x + dx[i];
            int new_y = cur.y + dy[i];

            if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;

            if (map[new_x][new_y] == 0 && dist[new_x][new_y][cur.broken] == 0) {
                dist[new_x][new_y][cur.broken] = dist[cur.x][cur.y][cur.broken] + 1;
                q.push({new_x, new_y, cur.broken});
            }
            else if (map[new_x][new_y] == 1 && cur.broken == 0) {
                if (dist[new_x][new_y][1] == 0) {
                    dist[new_x][new_y][1] = dist[cur.x][cur.y][0] + 1;
                    q.push({new_x, new_y, 1});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    map.assign(n, vector<int>(m));
    dist.assign(n, vector<vector<int>>(m, vector<int>(2,0)));

    for (int i = 0; i < n; i++) {
        string input; cin >> input;
        for (int j = 0; j < m; j++) {
            map[i][j] = input[j] - '0';
        }
    }

    bfs();

    int res_0_broken = dist[n-1][m-1][0];
    int res_1_broken = dist[n-1][m-1][1];

    if (res_0_broken == 0 && res_1_broken == 0) {
        cout << -1;
    }
    else if (res_0_broken == 0) {
        cout << res_1_broken;
    } 
    else if (res_1_broken == 0) {
        cout << res_0_broken;
    } else {
        cout << min(res_0_broken, res_1_broken);
    }
}