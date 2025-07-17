#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

vector<ll> divisors;

void get_divs(ll n, vector<ll>& v) {
    ll sq = sqrt(n);
    for (ll i = 1; i <= sq; i++) {
        if (n % i == 0) {
            v.push_back(i);
            if (i != n/i) v.push_back(n/i);
        }
    }
    sort(v.begin(), v.end());
}

ll gcd(ll a, ll b) {
    while(b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll a, b, L;
    cin >> a >> b >> L;

    ll ab_lcm = lcm(a, b);
    get_divs(ab_lcm, divisors);
    
    for (int i = 0; i < divisors.size(); i++) {
        ll target = ((L*divisors[i]) / ab_lcm);
        if (gcd(ab_lcm, target) != divisors[i]) continue;
        if ((ab_lcm  / divisors[i]) * target == L) {
            cout << target;
            return 0;
        }
    }
    cout << -1; 
}