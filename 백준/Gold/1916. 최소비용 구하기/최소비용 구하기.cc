#include <iostream>
#include <vector>
using namespace std;
#define INF ~0U >> 2

int find_min(vector<int> arr, vector<bool> visited) {
    int min = INF;
    int minIdx = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < min && !visited[i]) {
            min = arr[i];
            minIdx = i;
        }
    }
    // cout << "minIdx is : " << minIdx << endl;
    return minIdx;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v;
    vector<int> row(n, INF);
    for (int i = 0; i < n; i++) {
        v.push_back(row);
        v[i][i] = 0;
    }

    int start, dest;
    for (int i = 0; i < m; i++) {
        int s, d, c;
        cin >> s >> d >> c;
        if (v[s-1][d-1] > c) {
            v[s-1][d-1] = c;
        }
    }  

    cin >> start >> dest;
    start--;
    dest--;
    // // for debugging
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         int val = v[i][j];
    //         if (val == INF) { cout << "INF "; }
    //         else { cout << val << " "; }
    //     }
    //     cout << endl;
    // }
    
    //dijkstra
    vector<bool> visited(n, false);
    vector<int> d(n, INF);
    visited[start] = true;
    for (int i = 0; i < n; i++) {
        d[i] = v[start][i];
    }
    for (int i = 0; i < n-2; i++) {
        int cur = find_min(d, visited);
        if (cur == -1) break;
        visited[cur] = true;
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                if (d[cur] + v[cur][j] < d[j]) {
                    d[j] = d[cur] + v[cur][j];
                }
            }
        }
    }

    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << d[i] << " ";
    // }
    // cout << endl;

    cout << d[dest];
}

