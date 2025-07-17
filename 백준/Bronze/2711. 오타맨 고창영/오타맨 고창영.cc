#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    int idx;
    string input;
    for (int i = 0; i < t; i++) {
        cin >> idx >> input;
        input.replace(idx-1, 1, "");
        cout << input << "\n";
    }
}