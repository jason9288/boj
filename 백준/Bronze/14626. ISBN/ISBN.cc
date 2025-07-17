#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string isbn; cin >> isbn;
    int unk_idx, sum = 0;

    for (int i = 0; i < 13; i++) {
        if (isbn[i] == '*') {
            unk_idx = i;
        } else {
            int num = isbn[i] - '0';
            sum += (i % 2 == 0) ? num : 3*num;
        }
    }

    int unknown;
    if (unk_idx % 2 != 0) {
        int tmp = (10 - (sum % 10)) % 10;
        unknown = (tmp * 7) % 10;
    } else {
        unknown = (10 - (sum % 10)) % 10;
    }

    cout << unknown;
}