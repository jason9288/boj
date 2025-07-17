#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a, b, x;
        cin >> a >> b >> x;
        cout << x / gcd(a,b) << endl;
    }
}