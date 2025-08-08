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

int main() {
    FAST_IO

    int n, m, d; cin >> n >> m >> d;
    cin.ignore();

    vector<vector<int>> ma;
    ma.push_back({});

    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);
        istringstream iss(s);
        int num;
        vector<int> ns;
        
        while (iss >> num) {
            ns.push_back(num);
        }
        
        ma.push_back(ns);
    }


    for (int i = 1; i <= n; i++) {
        sort(ma[i].begin(), ma[i].end());
    }

    for (int j = 0; j < m; j++) {
        for (int i = 2; i <= n; i++) {
            if (ma[i][j] + d*i <= ma[i-1][j] + d*(i-1)) {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";
    return 0;

}