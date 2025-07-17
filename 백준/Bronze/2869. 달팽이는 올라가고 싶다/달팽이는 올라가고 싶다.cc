#include <iostream>
using namespace std;

int main() {
    long long up, down, height;
    cin >> up >> down >> height;

    long long h = up - down;

    long long rest = height - up;


    
    if (rest % h == 0) {
        cout << (rest / h) + 1;
    } else {
        cout << (rest / h) + 2;
    }
}