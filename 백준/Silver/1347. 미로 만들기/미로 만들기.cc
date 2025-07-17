#include <iostream>
#include <vector>
using namespace std;

int changeDir(char a, int dir) {
    if (a == 'R') {
        if (dir+1 > 3) {
            return 0;
        }
        return dir+1;
    }
    if (a == 'L') {
        if (dir-1 < 0) {
            return 3;
        }
        return dir-1;
    }
    return -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    string input;
    cin >> n;
    cin >> input;

    int up = 50, down = 50, left = 50, right = 50;
    int dir = 1;

    char miro[101][101];
    fill(miro[0], miro[101], '#');
    int row = 50, col = 50;
    miro[row][col] = '.';

    for (char i : input) {
        if (i == 'F') {
            switch(dir) {
                case 0 :
                    col++;
                    if (right < col) right = col;
                    break;
                case 1 : 
                    row++;
                    if (down < row) down = row;
                    break;
                case 2 :
                    col--;
                    if (left > col) left = col;
                    break;
                case 3 :
                    row--;
                    if (up > row) up = row;
                    break;
            }
            miro[row][col] = '.';
        } else {
            dir = changeDir(i, dir);
        }
    }

    for (int i = up; i <= down; i++) {
        for (int j = left; j <= right; j++) {
            cout << miro[i][j];
        }
        cout << endl;
    }
}