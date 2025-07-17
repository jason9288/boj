#include <iostream>
using namespace std;

int cnt(int * arr, int idx) {
    int counter = 0;
    int depth = idx + 4;
    for ( ; idx < depth; idx++) {
        if (arr[idx] == 1) {
            counter += 1;
        }
    }
    return counter;
}

void printer(int cnt) {
    if (cnt == 0) {
        cout << "D";
    } else if (cnt == 1) {
        cout << "C";
    } else if (cnt == 2) {
        cout << "B";
    } else if (cnt == 3) {
        cout << "A";
    } else {
        cout << "E";
    }
}

int main() {
    int arr[12];
    for (int i = 0; i < 12; i++) {
        cin >> arr[i];
    }
    int cnt1, cnt2, cnt3;
    cnt1 = cnt(arr, 0);
    cnt2 = cnt(arr, 4);
    cnt3 = cnt(arr, 8);

    printer(cnt1);
    cout << endl;
    printer(cnt2);
    cout << endl;
    printer(cnt3);
}