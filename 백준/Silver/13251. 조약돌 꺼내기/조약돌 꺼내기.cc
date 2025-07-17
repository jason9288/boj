#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0, m, k, s;
    cin >> m;
    vector<int> arr(m, 0);
    for (int i = 0; i < m; i++) {
        arr[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        arr[i] += s;
        n += s;
    }
    cin >> k;
    long double sol = 0.0;
    for (int j = 0; j < m; j++) {
        long double q = 1.0;
        if (arr[j] < k) continue;
        for (int i = 0; i < k; i++) {
            q *= (long double)(arr[j]-i)/(n-i);
        }
        sol += q;
    }
    cout << fixed;
    cout.precision(15);
    cout << sol;

}