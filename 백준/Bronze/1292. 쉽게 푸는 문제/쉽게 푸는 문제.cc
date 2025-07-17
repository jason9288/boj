#include <iostream>
#define MAX 1001
using namespace std;

int main() {
    int arr[MAX];
    int counter = 1;
    int c_temp = 1;
    int num = 1;
    for(int i = 0; i < MAX; i++) {
        arr[i] = num;
        counter--;
        if (counter == 0) {
            counter = c_temp + 1;
            c_temp++;
            num++;
        }
    }
    int sum = 0;
    int a, b;
    cin >> a >> b;

    for (int i = a-1; i < b; i++) {
        sum += arr[i];
    }
    cout << sum;
}