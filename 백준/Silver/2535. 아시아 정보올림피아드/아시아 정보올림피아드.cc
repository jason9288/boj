#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct st {
    int nat, num, score;
};

int COMP_BY_SCORE(st x, st y) {
    return x.score < y.score; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, nats = 0; cin >> n;
    vector<st> list;

    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        list.push_back({a, b, c});
    }

    sort(list.begin(), list.end(), COMP_BY_SCORE);

    st gold, silver, bronze;

    gold = list.back();
    list.pop_back();
    silver = list.back();
    list.pop_back();

    if (gold.nat == silver.nat) {
        while (true) {
            if (list.back().nat != gold.nat) {
                bronze = list.back();
                break;
            }
            list.pop_back();
        }
    } else {
        bronze = list.back();
    }
    
    cout << gold.nat << " " << gold.num << endl;
    cout << silver.nat << " " << silver.num << endl;
    cout << bronze.nat << " " << bronze.num;
}