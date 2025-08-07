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

struct dt {
    int sco, remT;
};

stack<dt> d;
int n, score = 0;

int main() {
    FAST_IO
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int val; cin >> val;
        if (val == 0) {
            if (d.size() > 0) {
                d.top().remT--;
                if (d.top().remT == 0) {
                    score  += d.top().sco;
                    d.pop();
                }
            }
            continue;
        }
        int sc, t; cin >> sc >> t;
        if (t-1 == 0) {
            score += sc;
            continue;
        }
        d.push({sc, t-1});
    }

    cout << score;
}