#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;


    for (int j = n; j > 1; j--) {
        for (int p = 0; p < n-j; p++) {
            cout << " ";
        }
        for (int k = 0; k < (2*j - 1); k++) {
            cout << "*";
        }
        cout << endl;
    }
    
    for (int i = 0; i < n-1; i++) {
        cout << " ";
    }
    cout << "*" << endl;

    for (int j = 2; j <= n; j++) {
        for (int p = 0; p < n-j; p++) {
            cout << " ";
        }
        for (int k = 0; k < (2*j - 1); k++) {
            cout << "*";
        }
        cout << endl;
    }
    
}
