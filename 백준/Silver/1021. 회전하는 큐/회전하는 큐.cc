#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int n, m, cnt = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    deque<int> dq;

    for (int i = 0; i < n; i++) {
        dq.push_back(i+1);
    }
    
    for (int i = 0; i < m; i++) {
        int input; cin >> input;
        int idx = find(dq.begin(), dq.end(), input) - dq.begin();
        int a = idx;
        int b = n - idx;

        if (a <= b) {
            for (int j = 0; j < a; j++) {
                int tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
                cnt++;
            }
        } else {
            for (int j = 0; j < b; j++) {
                int tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
                cnt++;
            }
        }
        dq.pop_front();
        n--;
    }

    cout << cnt;
}