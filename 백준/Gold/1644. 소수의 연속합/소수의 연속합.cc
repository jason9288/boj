#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
constexpr bool ndebug = true;
#else
constexpr bool ndebug = false;
#endif
#define FAST_IO \
    if constexpr (ndebug) { cin.tie(nullptr); ios::sync_with_stdio(false); }

typedef long long ll;

vector<int> prime;
vector<int> isPrime;
vector<ll> accSum;

void getPrimeArr(int n) {
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= sqrt(n); i++) {
        if (!isPrime[i]) continue;
        for (int j = i*2; j <= n; j += i) {
            isPrime[j] = false;
        }
    }

    for (int i = 2; i < isPrime.size(); i++) {
        if (isPrime[i])
        prime.push_back(i);
    }
}



int main() {
    FAST_IO

    int n; cin >> n;
    isPrime.resize(n+1, true);
    
    getPrimeArr(n);

    accSum.resize(prime.size()+1, 0);
    for (int i = 1; i < accSum.size(); i++) {
        accSum[i] = accSum[i-1] + prime[i-1];
    }

    int cnt = 0;
    for (int i = 0; i < accSum.size(); i++) {
        if (i != 0 && prime[i-1] > n) break;
        for (int j = i; j < accSum.size(); j++) {
            if (j != 0 && prime[j-1] > n) break;
            ll sum;
            if (i == j) {
                continue;
            } else {
                sum = accSum[j] - accSum[i];
            }
            if (sum == n) {
                cnt++;
                break;
            } 
            if (sum > n) {
                break;
            }
        }
    }

    cout << cnt;



}