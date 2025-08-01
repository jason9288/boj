#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    if (a + b != b + a) cout << 0;
    else cout << 1;
}