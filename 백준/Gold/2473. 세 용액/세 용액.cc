#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    vector<ll> v;

    for (int i = 0; i < n; i++) {
        ll input; cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    vector<ll> answer(3, 0);

    ll min = 3000000000;
    for (int i = 0; i < n-1; i++) {
        ll t = v[i];
        int start = 0;
        int end = n-1;
        while (start < end) {
            if (start == i) {
                start++;
                continue;
            }
            if (end == i) {
                end--;
                continue;
            }
            // cout << "checking : " << t << " " << v[start] << " " << v[end] << endl;
            ll sum = t + v[start] + v[end];
            if (abs(sum) < min) {
                min = abs(sum);
                answer[0] = v[start];
                answer[1] = t;
                answer[2] = v[end];
            }
            if (sum == 0) break;
            else if (sum < 0) start++;
            else end--;
        }   
    }

    sort(answer.begin(), answer.end());
    cout << answer[0] << " " << answer[1] << " " << answer[2];
}