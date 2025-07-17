#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> info(n+1, 0);

    int count = m;
    while (count--) {
        int a, b;
        cin >> a >> b;

        info[a]++;
        info[b]++;
    }

    for (int i = 1; i <= n; i++) {
        cout << info[i] << endl;
    }
}