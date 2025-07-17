#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, a;
    cin >> n;
    map<int, int> m;

    int sum1 = 0;
    double exp = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        m[a]++;
        sum1 += a;
    }
    double avg = sum1/(double)n;

    for(auto iter = m.begin(); iter != m.end(); iter++) {
        exp += (iter->first)*(iter->second)/(double)n;
    }
    if (exp == 0) {
        cout << "divide by zero";
    } else {
        cout << fixed;
        cout.precision(2);
        cout << avg/(double)exp;
    }
}