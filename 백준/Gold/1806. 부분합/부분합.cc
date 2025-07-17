#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, s;
    cin >> n >> s;
    vector<int> seq(n+1, 0);
    seq[0] = 0;
    for (int i = 1; i <= n; i++) {
        int j; cin >> j;
        seq[i] = j;
    }

    vector<ll> S(n+1, 0);
    S[1] = seq[1];
    for (int i = 1; i <= n; i++) {
        S[i] = S[i-1] + seq[i];
    }

    int idx = -1;
    for (int i = 0; i <= n; i++) {
        if (S[i] >= s) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        cout << 0;
        return 0;
    }

    int start = 0;
    int end = idx;
    int len = 100001;
    while (true) {
        if (start > end || end > n || start < 0) break;
        ll subS = S[end] - S[start];

        if (subS >= s) {
            if (end-start < len) {
                len = end-start;
            }
            start++;
        } else {
            end++;
        }
    }
    int ans = (len == 100001) ? 0 : len;
    cout << ans;
}