#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;

void wave(int w, int n) {
    if (w > n) return;
    vector<int> s(w/2);
    vector<int> d(w/2);
    for (int i = 1; i <= w; i++) {
        if (i <= w/2) {
            s[i] = arr[i];
        } else {
            d[i-w/2] = arr[i];
        }
    }
    // s, d check
    // cout << "s : ";
    // for (int i = 1; i <= w/2; i++) {
    //     cout << s[i] << " ";
    // }
    // cout << endl << "d : ";
    // for (int i = 1; i <= w/2; i++) {
    //     cout << d[i] << " ";
    // }
    // cout << endl;

    for (int i = 1; i <= w/2; i++) {
        arr[2*i-1] = (s[i]+d[i])/2;
        arr[2*i] = (s[i]-d[i])/2;
    }

    wave(w*2, n);
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        arr.resize(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        wave(2, n);
        for (int i = 1; i <= n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}