#include <iostream>
#include <vector>
using namespace std;
#define val 1000000009

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int dp[1000001];

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 1000000; i++) {
        dp[i] = ((dp[i-1] % val + dp[i-2] % val) % val + (dp[i-3] % val) % val) % val;
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << dp[n] << endl;
    }
}