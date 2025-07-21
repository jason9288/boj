#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
constexpr bool ndebug = true;
#else
constexpr bool ndebug = false;
#endif
#define FAST_IO \
    if constexpr (ndebug) { cin.tie(nullptr); ios::sync_with_stdio(false); }
#define debug(x) \
    if constexpr (!ndebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugf(...) \
    if constexpr (!ndebug) { cout << "[DEBUG] "; printf(__VA_ARGS__); }
#define debugc(c) \
    if constexpr (!ndebug) { cout << "[DEBUG] " << #c << ": "; for (const auto& elem : c) cout << elem << " "; cout << '\n'; }
//=========================================================================================================


int sudoku[10][10];
bool col[10][10];
bool row[10][10];
bool square[10][10];

void init_arr() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            col[i][j] = false;
            row[i][j] = false;
            square[i][j] = false;
        }
    }
}

void print() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j];
        }
        cout << '\n';
    }
}

int getSquareNum(int x, int y) {
    return (x/3) * 3 + (y/3);
}

bool check(int z) {
    debugf("z = %d\n", z);
    if (z == 81) {
        print();
        return true;
    }
    int x = z / 9;
    int y = z % 9;

    if (sudoku[x][y] != 0) {
        return check(z+1);
    } else {
        for (int i = 1; i <= 9; i++) {
            if (!col[x][i] && !row[y][i] && !square[getSquareNum(x, y)][i]) {
                col[x][i] = true;
                row[y][i] = true;
                square[getSquareNum(x, y)][i] = true;
                sudoku[x][y] = i;

                if (check(z+1)) return true;

                col[x][i] = false;
                row[y][i] = false;
                square[getSquareNum(x, y)][i] = false;
                sudoku[x][y] = 0;
            }
        }
    }
    return false;
}

int main() {
    FAST_IO

    init_arr();
    for (int i = 0; i < 9; i++) {
        string input; cin >> input;
        for (int j = 0; j < 9; j++) {
            int s_n = input[j] - '0';
            sudoku[i][j] = s_n;
            if (s_n != 0) {
                col[i][s_n] = true;
                row[j][s_n] = true;
                square[getSquareNum(i,j)][s_n] = true;
            }
        }
    }
    check(0);
}