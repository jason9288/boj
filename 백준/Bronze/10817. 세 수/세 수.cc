#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[3];
    int a, b, c;

    cin >> a >> b >> c;
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;

    sort(arr, arr+3);

    cout << arr[1];
}
