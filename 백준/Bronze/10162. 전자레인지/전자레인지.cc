#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    int a, b, c;
    a = 0;
    b = 0;
    c = 0;

    a = t/300;
    t -= a*300;

    b = t/60;
    t -= b*60;

    c = t/10;
    t -= c*10;

    if (t != 0) {
        cout << "-1";
    } else {
        cout << a << " " << b << " " << c;
    }


}