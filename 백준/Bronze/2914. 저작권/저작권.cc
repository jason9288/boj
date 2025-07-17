#include <iostream>
using namespace std;

int main() {
    int im, avg;
    float songs;
    cin >> songs >> avg;
    im = songs * (avg-1);
    cout << im+1;
}