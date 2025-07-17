#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>
using namespace std;

long long getMaxPow(long long t) {
    if (t == 0) {
        return 0;
    }
    int n = 0;
    t = abs(t);

    while ((1LL << n) <= t) {
        n++;
    }
    n--;
    long long r = pow(2, n);
    return r;
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    long long pos_a = 0; // 현욱
    long long pos_b; // 형
    cin >> pos_b;

    // cout << getMaxPow(pos_b) << endl;

    int cnt = 0;
    long long maxP = getMaxPow(pos_b);
    while (true) {
        if (maxP == 0) {
            if (pos_b == 0) {
                cout << cnt;
                break;
            } else {
                cout << -1;
                break;
            }
        }
        if (pos_b >= 0) {
            pos_b -= maxP;
            cnt++;
            maxP = (maxP == 1) ? 0 : maxP/2;
            // cout << "posb = " << pos_b << " maxP : " << maxP << endl;
        } else if (pos_b < 0) {
            pos_b += maxP;
            cnt++;
            maxP = (maxP == 1) ? 0 : maxP/2;
            // cout << "posb = " << pos_b << " maxP : " << maxP << endl;
        } 
    }
    // auto end = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(end-start);
    // cout << "실행시간 : " << duration.count() << " ms" << endl;
}