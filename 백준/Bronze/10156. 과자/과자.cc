#include <iostream>
using namespace std;

int main() {
    int k, n, m; cin >> k >> n >> m;
    int price = k*n;
    int need = k*n - m;
    if (need < 0) {
        cout << 0;
    } else {
        cout << need;
    }
}