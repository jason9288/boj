#include <iostream>
using namespace std;

int main() {
    int input, max = -1, m;
    int sum = 0;
    int nums[1002];
    for (int i = 10; i < 1001; i+=10) {
        nums[i] = 0;
    }
    for (int i = 0; i < 10; i++) {
        cin >> input;
        sum += input;
        nums[input]++;
        if (max < nums[input]) {
            max = nums[input];
            m = input;
        }
    }
    int avg = sum / 10;
    cout << avg << endl << m;

}