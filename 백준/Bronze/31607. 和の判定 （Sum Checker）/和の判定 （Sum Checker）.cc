#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    if (a + b == c) {
        cout << 1;
    } else if (b + c == a) {
        cout << 1;
    } else if (a + c == b) {
        cout << 1;
    } else {
        cout << 0;
    }
}