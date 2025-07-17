#include <iostream>
#include <sstream>
#include <bitset>
#include <vector>
#include <string>
using namespace std;

string input(const string& ip) {
    stringstream ss(ip);
    string octet;
    string binary;

    while (getline(ss, octet, '.')) {
        int num = stoi(octet);
        binary += bitset<8>(num).to_string();
    }
    return binary;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<string> ipline;

    for (int i = 0; i < n; i++) {
        string in;
        cin >> in;
        ipline.push_back(input(in));
    }

    // for (string s : ipline) {
    //     cout << s << endl;
    // }

    int ans = 32;
    for (int k = 31; k >= 0; k--) {
        for (int i = 0; i < n-1; i++) {
            if (ipline[i][k] != ipline[i+1][k]) {
                ans = k;
                break;
            }
        }
    }
    cout << ans;
}