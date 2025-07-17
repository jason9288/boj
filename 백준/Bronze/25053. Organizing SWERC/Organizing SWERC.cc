#include <iostream>
using namespace std;

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int n; bool c[101]; int beauty[101]; 
        int diff[101]; int add[101];
        cin >> n;
        int sum = 0;
        for (int p = 0; p < 101; p++) { c[p] = false; }
        for (int j = 0; j < n; j++) {
            int a, b; cin >> a >> b;
            beauty[j] = a; diff[j] = b;
            if (c[b-1] == false) { 
                add[b-1] = a; sum += a;
                c[b-1] = true; 
            }
            else if (a >= add[b-1]) { 
                sum -= add[b-1]; 
                sum += a;
                add[b-1] = a;
            
            }
        }
        int cnt = 0;
        for (int j = 0; j < 10; j++) {
            if (c[j] == false) { cnt += 1; }
        }
        if (cnt != 0) { cout << "MOREPROBLEMS" << '\n'; }
        else { cout << sum << '\n'; }
    }
}