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

bool isPossible = false;

string revStr(string s) {
    string ret = "";
    for (int i = s.length()-1; i >= 0; i--) {
        ret += s[i];
    }

    return ret;
}


int main() {
    FAST_IO

    string s, t; cin >> s >> t;
    string rt = revStr(t);
    string tt = t;

    while (true) {
        // cout << tt << endl;
        if (tt.length() == 0) {
            cout << 0;
            return 0;
        }
        if (tt.length() == s.length() && tt == s) {
            cout << 1;
            return 0;
        }
        if (tt.back() == 'A') {
            tt.pop_back();
            continue;
        }
        if (tt.back() == 'B') {
            tt.pop_back();
            tt = revStr(tt);
            continue;
        }
    }
}