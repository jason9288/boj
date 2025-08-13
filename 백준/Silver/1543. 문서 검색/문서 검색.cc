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

    string t; getline(cin, t); 
    string u; getline(cin, u);

    int sum = 0;
    int i = 0;
    int temp;

    while (true) {
        debug(i);
        if (i == t.length()) break;
        if (t[i] != u[0]) {
            i++;
            continue;
        }

        bool chk = false;
        for (int j = 0; j < u.length(); j++) {
            if (t[i+j] != u[j]) {
                chk = false;
                break;
            }
            chk = true;
            temp = j;
        }

        if (chk) {
            sum++;
            i = temp + i + 1;
        } else {
            i++;
        }
    }

    cout << sum;
}