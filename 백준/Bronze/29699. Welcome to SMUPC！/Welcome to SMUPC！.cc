#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    string a = "WelcomeToSMUPC";
    if (n%14 == 0) {
        cout << 'C';
        return 0;
    }
    cout << a[n%14 - 1];
}