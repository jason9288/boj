#include <iostream>
using namespace std;

int main() {
    int N;

    cin >> N;

    for (int l = 0; l < N; ++l) {
        for (int i = 0; i < l; ++i) {
            cout << " ";
        }
        for (int j = N; j > l; --j) {
            cout << "*";
        }
        cout << endl;
    }
}