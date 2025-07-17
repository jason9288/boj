#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int getDistance(int x1, int y1, int x2, int y2);
int getLongestD(vector<pair<int, int>> l, int n, int k);
int getMin(int a, int b, int c) {
    return min(a, min(b, c));
}

int main() {
    int n, k, x, y;
    cin >> n >> k;
    vector<pair<int, int>> h_list(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        h_list[i] = make_pair(x, y);
    }
    cout << getLongestD(h_list, n, k);
}   

int getDistance(int x1, int y1, int x2, int y2) {
    return abs(x1-x2)+abs(y1-y2);
}

int getLongestD(vector<pair<int, int>> l, int n, int k) {  
    int max_d = -1;
    int maxmin = 9999999;
    if (k == 1) {
        for (int i = 0; i < n; i++) {
            int max_d = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int d = getDistance(l[i].first, l[i].second, l[j].first, l[j].second);
                max_d = max(max_d, d);
            }
            maxmin = min(maxmin, max_d);
        }
    } else if (k == 2) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {  // j = i + 1로 수정하여 중복 제거
                int max_d = 0;
                for (int q = 0; q < n; q++) {
                    if (q == i || q == j) continue;
                    int d1 = getDistance(l[i].first, l[i].second, l[q].first, l[q].second);
                    int d2 = getDistance(l[j].first, l[j].second, l[q].first, l[q].second);
                    // printf("대피소1 (%d, %d)와 %d번 집(%d, %d)의 거리 : %d\n", l[i].first, l[i].second, q+1,  l[q].first, l[q].second, d1);
                    // printf("대피소2 (%d, %d)와 %d번 집(%d, %d)의 거리 : %d\n\n", l[j].first, l[j].second, q+1, l[q].first, l[q].second, d2);
                    max_d = max(max_d, min(d1, d2));
                }
                maxmin = min(maxmin, max_d);
                // cout << "이 경우 가장 먼 거리 : " << maxmin << endl;
                // cout<< "-----------------------------" <<endl;
            }
        }
    } else {  // k > 2
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {  // j = i + 1로 중복 제거
                for (int u = j + 1; u < n; u++) {  // u = j + 1로 중복 제거
                    int max_d = 0;
                    for (int v = 0; v < n; v++) {
                        if (v == i || v == j || v == u) continue;
                        int d1 = getDistance(l[i].first, l[i].second, l[v].first, l[v].second);
                        int d2 = getDistance(l[j].first, l[j].second, l[v].first, l[v].second);
                        int d3 = getDistance(l[u].first, l[u].second, l[v].first, l[v].second);
                        max_d = max(max_d, getMin(d1, d2, d3));
                    }
                    maxmin = min(maxmin, max_d);
                }
            }
        }
    }

    return maxmin;
}


