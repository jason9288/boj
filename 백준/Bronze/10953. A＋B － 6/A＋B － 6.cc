#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    string input;
    int a, b;

    for (int i = 0; i < t; i++){
        cin >> input;
        int delimeter = input.find(",");
        string a = input.substr(0, delimeter);
        string b = input.substr(2);

        int ai = stoi(a);
        int bi = stoi(b);
        cout << ai+bi<< endl;
    }
}
