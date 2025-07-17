#include <iostream>
#include <map>
using namespace std;

int main() {
    map<char, int> m = {        
        {'A', 0},
        {'G', 1},
        {'C', 2},
        {'T', 3}
    };
    string table[4][4] = {
        {"A", "C", "A", "G"},
        {"C", "G", "T", "A"},
        {"A", "T", "C", "G"},
        {"G", "A", "G", "T"}
    };
    int n;
    cin >> n;
    string s;
    cin >> s;

    while (s.length() > 1) {
        char s_n1 = s[s.length()-2];
        char s_n2 = s[s.length()-1];
        string rep = table[m[s_n1]][m[s_n2]]+"";
        s.replace(s.length()-2, 2, rep);
    }
    cout << s;
}   
