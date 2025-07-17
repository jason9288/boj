#include <iostream>
#include <vector>
using namespace std;



int main() {
    int list[7];
    for (int i = 0; i < 7; i++) {
        cin >> list[i];
    }

    vector<int> odd_list(1, 0);

    for (int i = 0; i < 7; i++) {
        if (list[i] % 2 != 0) {
            odd_list.push_back(list[i]);
        } 
    }

    int odd_sum = 0;
    int odd_min = 101;

    if (odd_list.size() > 1) {
        for (int i = 1; i < odd_list.size(); i++) {
            odd_sum += odd_list[i];
            if (odd_min > odd_list[i]) {
                odd_min = odd_list[i];
            }
        }
        cout << odd_sum << endl << odd_min;
    } else {
        cout << "-1";
    }



}