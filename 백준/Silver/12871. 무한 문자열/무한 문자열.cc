#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    string s1 = "", s2 = "";

    for (int i = 0; i < a.length(); i++) {
        s1 += b;
    }
    for (int i = 0; i < b.length(); i++) {
        s2 += a;
    }

    if (s1 == s2) cout << 1;
    else cout << 0;
}