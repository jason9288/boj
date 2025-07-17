#include <iostream>
using namespace std;

int main() {
    long long s;
    long long sum = 0;
    int num = 1;


    cin >> s;


    while (true) {
        sum += num;
        if (sum > s) {
            num--;
            break;
        }
        num++;
    }

    cout << num << endl;
}