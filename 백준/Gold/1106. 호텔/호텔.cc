#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000000

struct Val {
    int cost, num;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int C, N; cin >> C >> N;
    vector<Val> info; 
    vector<int> c(C + 2000, MAX);
    c[0] = 0;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        info.push_back({a, b});
    }

    for (auto x : info) {
        for (int i = x.num; i < c.size(); i++) {
            c[i] = min(c[i], c[i-x.num] + x.cost);
        }
    }

    int ans = c[C];
    for (int i = C; i < c.size(); i++) {
        if (ans > c[i]) {
            ans = c[i];
        }
    }
    cout << ans;
}