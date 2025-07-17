#include <iostream>
using namespace std;

int b = 0;

int fib_dp(int n) {
    int dp[41];
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        b++;
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    int k = fib_dp(n);

    cout << k << " " << b;
}