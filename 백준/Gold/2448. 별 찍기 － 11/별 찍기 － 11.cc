#include <iostream>
#include <cstring>
using namespace std;

char s[3072][6144];

void star(int n, int r, int c) {
    if (n == 3) {
        s[r][c] = '*';
        s[r+1][c-1] = '*';
        s[r+1][c] = ' ';
        s[r+1][c+1] = '*';
        for (int i = 0; i < 5; i++) {
            s[r+2][c-2+i] = '*';
        }
        return;
    }
    star(n/2, r, c);
    star(n/2, r+n/2, c-n/2);
    star(n/2, r+n/2, c+n/2);
}

int main() {
    int n;
    cin >> n;
    memset(s, ' ', sizeof(s));

    star(n, 0, n-1);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2*n; j++) {
            cout << s[i][j];
        }
        cout << endl;
    }
}
