#include <iostream>
#include <map>
using namespace std;

int main() {
    map<char, string> m;
    m.insert({'A', "a"});
    m.insert({'B', "v"});
    m.insert({'E', "ye"});
    m.insert({'H', "n"});
    m.insert({'P', "r"});
    m.insert({'C', "s"});
    m.insert({'Y', "u"});
    m.insert({'X', "h"});
    m.insert({'K', "k"});
    m.insert({'M', "m"});
    m.insert({'O', "o"});
    m.insert({'T', "t"});
    string input, output = "";
    cin >> input;
    for (int i = 0; i < input.length(); i++) {
        output += m[input[i]];
    }
    cout << output;
}