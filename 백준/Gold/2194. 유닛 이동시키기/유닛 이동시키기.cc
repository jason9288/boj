#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Point {
    int x, y;
};

struct State {
    int x, y, move;
};

int N, M, A, B, K;
vector<vector<int>> map;
vector<vector<bool>> visited;
Point s, e; 

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs() {
    State cur = {s.x, s.y, 0};
    queue<State> q;
    q.push(cur);
    visited[cur.x][cur.y] = true;

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (cur.x == e.x && cur.y == e.y) break;

        for (int i = 0; i < 4; i++) {
            int nxtx = cur.x + dx[i];
            int nxty = cur.y + dy[i];

            if (nxtx >= 1 && nxtx+A-1 <= N && nxty >= 1 && nxty+B-1 <= M && map[nxtx][nxty] != -1 && visited[nxtx][nxty] != true) {
                bool noObs = true;
                if (i == 0) { // up
                    for (int i = cur.y; i <= cur.y+B-1; i++) {
                        if (map[nxtx][i] == -1) {
                            noObs = false;
                            break;
                        } 
                    }

                } else if (i == 1) { // down
                    for (int i = cur.y; i <= cur.y+B-1; i++) {
                        if (map[nxtx+A-1][i] == -1) {
                            noObs = false;
                            break;
                        } 
                    }

                } else if (i == 2) { // left
                    for (int i = cur.x; i <= cur.x+A-1; i++) {
                        if (map[i][nxty] == -1) {
                            noObs = false;
                            break;
                        } 
                    }

                } else { // right
                    for (int i = cur.x; i <= cur.x+A-1; i++) {
                        if (map[i][nxty+B-1] == -1) {
                            noObs = false;
                            break;
                        } 
                    }
                }
                if (noObs && !visited[nxtx][nxty]) {
                    visited[nxtx][nxty] = true;
                    q.push({nxtx, nxty, cur.move + 1});
                }
            }
        }
    }
    
    return (cur.x == e.x && cur.y == e.y) ? cur.move : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> A >> B >> K;
    visited.resize(N+1, vector<bool>(M+1, false));
    map.resize(N+1, vector<int>(M+1, 0));
    for (int i = 0; i < K; i++) {
        int row, col; cin >> row >> col;
        map[row][col] = -1;
    }
    
    int in1, in2;
    cin >> in1 >> in2;
    s.x = in1; s.y = in2;
    cin >> in1 >> in2;
    e.x = in1; e.y = in2;

    for (int i = s.x; i < s.x+A; i++) {
        for (int j = s.y; j < s.y+B; j++) {
            if (map[i][j] == -1) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << bfs();
}