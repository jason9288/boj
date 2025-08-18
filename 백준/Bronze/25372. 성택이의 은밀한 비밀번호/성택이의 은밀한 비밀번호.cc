#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    
    while (n--) {
        string a; cin >> a;
        
        if (a.length() >= 6 && a.length() < 10) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}