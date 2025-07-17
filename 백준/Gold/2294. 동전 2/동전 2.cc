#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10001


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    vector<int> coins;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        coins.push_back(input);
    }

    vector<int> cnt(k+1, MAX);
    cnt[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= k; j++) {
            cnt[j] = min(cnt[j], cnt[j-coins[i]]+1);
        }
    }
    int result = cnt[k];
    if (result == MAX) {
        cout << -1;
    } else {
        cout << result;
    }
}