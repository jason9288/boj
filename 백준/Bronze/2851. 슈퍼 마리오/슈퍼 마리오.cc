#include <iostream>
#include <cmath>
using namespace std;

int find_idx(int* gap) {
    int idx;
    int min = 200000;
    for (int i = 0; i < 10; i++) {
        if (gap[i] <= min) {
            min = gap[i];
            idx = i;
        }
    }
    return idx;
}

int main() {
    int mush[10], score[10], gap[10];
    int sre = 0;
    for (int i = 0; i < 10; ++i) {
        cin >> mush[i];
    }
    for (int i = 0; i < 10; ++i) {
        sre += mush[i];
        score[i] = sre;
        gap[i] = abs(score[i] - 100);
    }  
    cout << score[find_idx(gap)];
}