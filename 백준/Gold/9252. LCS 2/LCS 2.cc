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

vector<vector<pair<int, int>>> m;

void print_lcs(string x, int i, int j) {
    debugf("print i, j : %d, %d\n", i, j)
    if (i == 0 || j == 0) return;
    if (m[i][j].second == 2) {
        print_lcs(x, i-1, j-1);
        cout << x[i-1];
    } 
    else if (m[i][j].second == 1) {
        print_lcs(x, i-1, j);
    } 
    else if (m[i][j].second == 0) {
        print_lcs(x, i, j-1);
    }
    else {
        return;
    }
}

int main() {
    FAST_IO

    m.resize(1001, vector<pair<int, int>>(1001, {0, 8}));
    // first - length, second - direction (0 left, 1 up, 2 diag)

    string a, b; cin >> a >> b;

    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            debugf("i, j : %d, %d\n", i, j)
            if (a[i-1] == b[j-1]) {
                m[i][j].first = m[i-1][j-1].first + 1;
                m[i][j].second = 2;
            }
            else if (m[i-1][j].first >= m[i][j-1].first) {
                m[i][j].first = m[i-1][j].first;
                m[i][j].second = 1;
            } 
            else {
                m[i][j].first = m[i][j-1].first;
                m[i][j].second = 0;
            }
        }
    }
    int length = m[a.length()][b.length()].first;

    if (length == 0) {
        cout << length;
        return 0;
    } else {
        cout << length << '\n';
        print_lcs(a, a.length(), b.length());
    }
}