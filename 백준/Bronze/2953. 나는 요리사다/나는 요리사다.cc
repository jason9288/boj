#include <iostream>
#include <vector>
using namespace std;

#define MAX ~0U >> 2



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int max = -1;
    int winner = -1;
    for (int i = 1; i <= 5; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int sum = a+b+c+d;
        if (max < sum) {
            winner = i;
            max = sum;
        }
    }
    cout << winner << " " << max;
}