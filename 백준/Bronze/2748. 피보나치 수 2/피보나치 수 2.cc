#include <iostream>
using namespace std;

long long dynamic_fibo(long long* arr, int n) {
    if (arr[n] == -1) {
        arr[n] = dynamic_fibo(arr, n-1) + dynamic_fibo(arr, n-2);
    }
    return arr[n];

}

int main() {
    int n; cin >> n;

    long long arr[91];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < 91; i++) {
        arr[i] = -1;
    }

    cout << dynamic_fibo(arr, n);
}