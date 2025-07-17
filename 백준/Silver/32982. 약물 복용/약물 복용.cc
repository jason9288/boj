#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int m_s, m_e, l_s, l_e, d_s, d_e;
    cin >> m_s >> m_e >> l_s >> l_e >> d_s >> d_e;

    int time = m_e;
    for (int i = 1; i <= n; i++) {
        if (time + k < l_s) {
            cout << "NO";
            return 0;
        }
        time = min(l_e, time + k);
        if (time + k < d_s) {
            cout << "NO";
            return 0;
        }
        time = min(d_e, time + k);

        if (i < n) {
            if (time + k < m_s + 1440) {
                cout << "NO";
                return 0;
            }
            time = min(m_e, time + k - 1440);
        }
    }

    cout << "YES";
    return 0;
} 