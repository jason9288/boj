#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
constexpr bool ndebug = true;
#else
constexpr bool ndebug = false;
#endif
#define FAST_IO \
    if constexpr (ndebug) { cin.tie(nullptr); ios::sync_with_stdio(false); }
#define debug(x) \
    if constexpr (!ndebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugf(...) \
    if constexpr (!ndebug) { cout << "[DEBUG] "; printf(__VA_ARGS__); }
#define debugc(c) \
    if constexpr (!ndebug) { cout << "[DEBUG] " << #c << ": "; for (const auto& elem : c) cout << elem << " "; cout << '\n'; }
//=========================================================================================================
typedef long long ll;

vector<int> p;
vector<vector<ll>> m;

int main() {
    FAST_IO

    int n; cin >> n;
    m.resize(n+1, vector<ll>(n+1, 0));
    int a0, a1; cin >> a0 >> a1;
    p.push_back(a0);
    p.push_back(a1);

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        if (p.back() == a) {
            p.push_back(b);
        } 
    }

    for (int l = 2; l < n+1; l++) {
        for (int i = 1; i <= n-l+1; i++) {
            int j = i + l - 1;
            if (i > j) continue;
            if (i == j) m[i][j] = 0;
            if (i < j) {
                ll min = ~0U >> 2;
                for (int k = i; k < j; k++) {
                    ll check = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                    if (check < min) {
                        min = check;
                    }
                }
                m[i][j] = min;
            }
        }
    }

    cout << m[1][n];
}