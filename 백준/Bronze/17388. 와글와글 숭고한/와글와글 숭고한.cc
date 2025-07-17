#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int s, k, h;
    cin >> s >> k >> h;

    if (s+h+k < 100) {
        if (s < k && s < h) {
            cout << "Soongsil";
        }
        if (k < s && k < h) {
            cout << "Korea";
        }
        if (h < s && h < k) {
            cout << "Hanyang";
        }
    } else {
        cout << "OK";
    }
}