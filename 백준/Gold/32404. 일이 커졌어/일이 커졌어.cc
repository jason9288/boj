#include <iostream>
#include <vector>
#include <deque>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<int> v(n+1, 0);
    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    for (int i = n; i >= 1; i--) {
        if (i % 2 != 0) {
            v[i] = dq.back();
            dq.pop_back();
        } else {
            v[i] = dq.front();
            dq.pop_front();
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }
}