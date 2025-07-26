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

int card[1000001]; // x번 카드를 가지고 있는 지 여부 card[x]
int player[100001]; // i번 플레이어의 카드 번호 player[i]
int score[1000001]; // x번 카드를 가진 플레이어의 점수 score[x]

int main() {
    FAST_IO

    int n; cin >> n;
    // visited.resize(n+1, vector<bool>(n+1, false));
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        card[k] = 1;
        player[i] = k;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = player[i]*2; j < 1000001; j+=player[i]) {
            if (card[j] == 1) {
                score[player[i]]++;
                score[j]--;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << score[player[i]] << " ";
    }
}
