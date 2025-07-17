#include <iostream>
#include <string>
using namespace std;

int main() {
    string list[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    string alpha;
    string replace_str = "A";

    cin >> alpha;

    for (string s : list) {
        while (alpha.find(s) != string::npos) {
            alpha.replace(alpha.find(s), s.length(), replace_str);
        }
    }


    cout << alpha.length();
}
