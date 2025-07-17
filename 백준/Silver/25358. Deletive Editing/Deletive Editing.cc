#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        string s, t;
        cin >> s >> t;

        unordered_map<char, int> sa, ta;

        for (char c : s) sa[c]++;
        for (char c : t) ta[c]++;

        bool possible = true;
        for (char c = 'A'; c <= 'Z'; c++) {
            if (sa[c] < ta[c]) {
                possible = false;
                break;
            }
        }
        if (!possible) {
            cout << "NO" << endl;
            continue;
        }

        unordered_map<char, int> sadta;
        for (char c = 'A'; c <= 'Z'; c++) {
            sadta[c] = sa[c] - ta[c];
        }
        for (char c = 'A'; c <= 'Z'; c++) {
            while (sadta[c] > 0) {
                s.erase(s.begin() + s.find(c));
                sadta[c]--;
            }
            if (s == t) {
                cout << "YES" << endl;
                break;
            }
        }
        if (s != t) {
            cout << "NO" << endl;
            continue;
        }
    }
}