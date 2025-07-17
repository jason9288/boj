#include <iostream>
#include <vector>
using namespace std;

int n, k, in;
int cntr = 0;

int insertion_sort(vector<int> v, int k) {
    int loc, cur, temp = -1;
    for (int i = 1; i < n; i++) {
        loc = i-1;
        cur = v[i];

        while (0 <= loc && cur < v[loc]) {
            v[loc+1] = v[loc];
            cntr++;
            if (cntr == k) temp = v[loc];
            loc--;
        }
        if (loc+1 != i) {
            v[loc+1] = cur;
            cntr++;
            if (cntr == k) temp = cur;
        }    
    }
    return temp;
}

int main() {
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> in;
        v[i] = in;
    }
    int sol = insertion_sort(v, k);
    cout << sol;
}