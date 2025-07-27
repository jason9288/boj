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
#define MAXN 500002

vector<int> S;

void printarr() {
    for (int i = 0; i < S.size(); i++) {
        cout << S[i] << " ";  
    }
    cout << endl;
}

int Find(int x) {
    if (S[x] < 0 || S[x] == MAXN) return x;
    else return (S[x] = Find(S[x]));
}

bool Union(int x, int y) {
    int r1 = Find(x);
    int r2 = Find(y);
    debugf("r1 r2 : %d %d\n", r1, r2);
    if (r1 == r2) return false;
    debugf("[1] sr1 sr2 : %d %d\n", S[r1], S[r2]);
    
    if (S[r2] < S[r1]) {
        S[r1] = r2;
    } else {
        if (S[r2] == S[r1]) {
            if (S[r1] == MAXN) S[r1] = 0;
            S[r1]--;
        }
        S[r2] = r1;
    }
    debugf("[2] sr1 sr2 : %d %d\n", S[r1], S[r2]);
    return true;
}

int main() {
    FAST_IO

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        S.push_back(MAXN);
    }

    for (int i = 1; i <= m; i++) {
        int s, e; cin >> s >> e;
        // cout << '\n';
        debugf("%d : %d, %d\n", i, s, e);
        if (!Union(s, e)) {
            cout << i;
            return 0;
        }
        // printarr();
    }

    cout << 0;
}