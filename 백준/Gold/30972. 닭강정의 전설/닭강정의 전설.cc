#include <iostream>
#include <vector>
using namespace std;

struct bound {
    int r1, c1, r2, c2;
};

vector<vector<int>> grid;
int n, q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        vector<int> t;
        for (int j = 0; j < n; j++) {
            int a; cin >> a;
            t.push_back(a);
        }
        grid.push_back(t);
    }

    vector<bound> s;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        s.push_back({a, b, c, d});
    }

    vector<vector<int>> sum(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + grid[i-1][j-1];
        }
    }

    for (int i = 0; i < q; i++) {
        int m = 0;

        int k = sum[s[i].r2][s[i].c2] - sum[s[i].r2][s[i].c1-1] - sum[s[i].r1-1][s[i].c2] + sum[s[i].r1-1][s[i].c1-1];
        if ((s[i].r2-s[i].r1) > 1 && s[i].c2-s[i].c1 > 1) {
            m = sum[s[i].r2-1][s[i].c2-1] - sum[s[i].r2-1][s[i].c1] - sum[s[i].r1][s[i].c2-1] + sum[s[i].r1][s[i].c1];
        }

        int ans = -k + 2*m;
        cout << ans << endl;
    }
}