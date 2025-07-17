#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t>0) {
        int a, b;
        cin >> a >> b;

        int result = a;
        b = b % 4 + 4;

        for (int i = 2; i <= b; i++) {
            result = (result*a)%10;
        }

        if (result == 0) {
            result = 10;
        }

        cout << result << endl;
        t--;
    }
}