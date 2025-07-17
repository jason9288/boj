#include <iostream>
using namespace std;

int w[101][101][101];

void do_dp() {
    for (int a = -50; a <= 50; a++) {
        for (int b = -50; b <= 50; b++) {
            for (int c = -50; c <= 50; c++) {
                int A = a + 50; int B = b + 50; int C = c + 50;
                if (A <= 50 || B <= 50 || C <= 50) {
                    w[A][B][C] = 1;
                    continue;
                }
                if (A > 70 || B > 70 || C > 70) {
                    w[A][B][C] = w[70][70][70];
                    continue;
                }
                if (A < B && B < C) {
                    w[A][B][C] = w[A][B][C-1] + w[A][B-1][C-1] - w[A][B-1][C];
                    continue;
                }
                w[A][B][C] = w[A-1][B][C] + w[A-1][B-1][C] + w[A-1][B][C-1]- w[A-1][B-1][C-1];
            }
        }
    }
}

int main() {
    for (int i = 0; i < 2; i++) {
        do_dp();
    }
    int a, b, c;
    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        int A = a + 50; int B = b + 50; int C = c + 50;
        printf("w(%d, %d, %d) = %d\n", a, b, c, w[A][B][C]);
    }
}