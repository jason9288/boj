#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX ~0U >> 2



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> packages;
    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;
        packages.push_back(in);
    }

    sort(packages.rbegin(), packages.rend());


    int np = min(m+k, n);

    long long a=0, b=0;

    for (int i = 0; i < np; i++) {
        a += packages[i];
    }
    for (int i = 0; i < n; i++) {
        b += packages[i];
    }

    cout.precision(9);
    cout << (a / (double) b) * 100;
}