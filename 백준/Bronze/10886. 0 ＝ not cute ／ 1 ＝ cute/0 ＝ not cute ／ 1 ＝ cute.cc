#include <iostream>
using namespace std;

int main() {
    int n, a, b;
    a = 0;
    b = 0;
    cin >> n;
    int c; 

    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == 1) {
            a++;
        } else {
            b++;
        }
    }

    if (a > b) {
        cout << "Junhee is cute!";
    } else {
        cout << "Junhee is not cute!";
    }
}