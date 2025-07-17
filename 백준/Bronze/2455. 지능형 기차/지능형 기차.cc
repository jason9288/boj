#include <iostream>
#include <algorithm>
using namespace std;

int cntr(int idx, int* arr) {
    int cnt = 0;
    cnt -= arr[idx];
    cnt += arr[idx+1];
    return cnt;
}

int main() {
    int arr[8];
    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
    }

    int cnt = 0;
    int counter[4];

    for (int i = 0; i < 4; i++) {
        counter[i] = 0;
    }

    for (int i = 0; i < 4; i++) {
        cnt += cntr(i*2, arr);
        counter[i] = cnt;
    }

    pair<int*, int*> minmax = minmax_element(begin(counter), end(counter));
    cout << *(minmax.second);
}