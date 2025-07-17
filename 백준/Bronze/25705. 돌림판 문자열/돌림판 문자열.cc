#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, m, i = 0;
    map<char, int> mp;
    cin >> n;
    char dolimpan[n];
    string s1; 
    cin >> s1;
    for (char c : s1) {
        dolimpan[i] = c;
        mp[c]++;
        i++;
    }
    cin >> m;
    string S;
    cin >> S;
    for (char c : S) {
        if (mp[c] == 0) {
            cout << -1;
            return 0;
        }
    }
    string res = "";
    int pos = n-1;
    int cnt = 0;
    int idx = 0;
    while (res != S) {
        pos = (pos+1)%n;
        cnt++;
        if (S[idx] == dolimpan[pos]) {
            res += dolimpan[pos];
            idx++;
        }
    }
    cout << cnt;
}   

