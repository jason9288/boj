#include <iostream>
#include <vector>
using namespace std;

struct point {
    long long x;
    long long y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<point> v;

    for (int i = 0; i < n; i++) {
        long long x, y; cin >> x >> y;
        v.push_back({x, y});
    }

    double ans;
    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        if (i == n-1) {
            sum1 += v[i].x * v[0].y;
            sum2 += v[i].y * v[0].x;
            break;
        }
        sum1 += v[i].x * v[i+1].y;
        sum2 += v[i].y * v[i+1].x;
    }
    ans = 0.5 * abs(sum1 - sum2);

    cout << fixed;
    cout.precision(1);
    cout << ans;

}