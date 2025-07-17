#include <iostream>
#include <vector>
using namespace std;

int main() {
    int prize = 0;
    int maxprize = -1;
    int n;
    cin >> n;
   
    while (n--) {
        int arr[3];
        for (int i = 0; i < 3; i++) {
            cin >> arr[i];
        }
        if (arr[0] == arr[1] && arr[1] == arr[2]) {
            prize = 10000 + (arr[0] * 1000);
        } 
        else if ((arr[0]==arr[1] && arr[1]!=arr[2])||(arr[1]==arr[2] && arr[0]!=arr[1])||(arr[0]==arr[2] && arr[1]!=arr[2])) {
            if (arr[0]==arr[1]) prize = 1000 + (arr[0] * 100);
            if (arr[1]==arr[2]) prize = 1000 + (arr[1] * 100);
            if (arr[0]==arr[2]) prize = 1000 + (arr[0] * 100);
        }
        else {
            int max = -1;
            for (int i = 0; i < 3; i++) {
                if (max < arr[i]) {
                    max = arr[i];
                }
            }
            prize = max * 100;
        }
        if (maxprize < prize) {
            maxprize = prize;
        }
    }
    cout << maxprize;
    
    
}