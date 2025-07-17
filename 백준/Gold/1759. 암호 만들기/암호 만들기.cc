#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isVowel(char input) {
    if (input == 'a' || input == 'e' || input == 'i' || input == 'o' || input == 'u') return true;
    return false;
}

void backtrack(vector<char>& alpha, int len, string ans, int idx, int v, int c) {
    if (ans.length() == len) {
        if (v >= 1 && c >= 2) {
            cout << ans << endl;
        } 
        return;
    }

    for (int i = idx; i < alpha.size(); i++) {
        if (ans.find(alpha[i]) == string::npos) {
            ans += alpha[i];
            if (isVowel(alpha[i])) {
                backtrack(alpha, len, ans, i+1, v+1, c);
            } else {
                backtrack(alpha, len, ans, i+1, v, c+1);
            }
            ans.pop_back();
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int L, C;
    cin >> L >> C;

    vector<char> alpha;

    for (int i = 0; i < C; i++) {
        char input;
        cin >> input;

        alpha.push_back(input);
    }
    sort(alpha.begin(), alpha.end());
    backtrack(alpha, L, "", 0, 0, 0);
}