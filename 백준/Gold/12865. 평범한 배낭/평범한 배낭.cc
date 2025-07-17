#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k, w, v;
    cin >> n >> k;
    pair<int, int> p[n+1][2];
    int dp[n+1][k+1];
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < k+1; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i < n+1; i++) {
        cin >> w >> v;
        p[i]->first = w;
        p[i]->second = v;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (p[i]->first <= j) {
                if (p[i]->second + dp[i-1][j-p[i]->first] > dp[i-1][j]) {
                    dp[i][j] = p[i]->second + dp[i-1][j-p[i]->first];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][k];
}