#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    int info[n+1][n+1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> info[i][j];
        }
    }

    vector<int> fr(n+1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            for (int k = 1; k <= 5; k++) {
                if (info[i][k] == info[j][k]) {
                    fr[i]++;
                    break;
                }
            }
        }
    }

    int max = -1;
    int ans = 0;
    // cout << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << fr[i] << " ";
    // }
    // cout << endl;
    for (int i = n; i >= 1; i--) {
        if (fr[i] >= max) {
            ans = i;
            max = fr[i];
        }
    }
    cout << ans;
}