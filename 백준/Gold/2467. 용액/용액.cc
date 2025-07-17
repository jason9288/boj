#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    vector<ll> v;

    bool minus = false, plus = false;
    int plus_start;
    for (int i = 0; i < n; i++) {
        ll input; cin >> input;
        v.push_back(input);
    }

    pair<ll, ll> answer;

    int start = 0;
    int end = n-1;
    ll min = 2000000000;
    while (start < end) {
        ll sum = v[start] + v[end];
        if (abs(sum) < min) {
            min = abs(sum);
            answer = {v[start], v[end]};
        }
        if (sum == 0) break;
        else if (sum < 0) start++;
        else end--;
    }   

    cout << answer.first << " " << answer.second;
}