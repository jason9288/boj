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

typedef unsigned long long ull;

int main() {
    FAST_IO

    vector<ull> t;

    t.assign(36, 0);

    int n; cin >> n;

    t[0] = 1;
    t[1] = 1;
    int i = 0, j = 1;
    int k = 2;
    while (true) {
        if (i >= k || j < 0) {
            k++;
            i = 0;
            j = k-1;
            continue;
        }
        if (k > n) break;

        debugf("adding t[%d] -> t[%d]*t[%d]\n", k, i, j);
        t[k] += t[i]*t[j];

        i++; j--;
    }

    cout << t[n];
}