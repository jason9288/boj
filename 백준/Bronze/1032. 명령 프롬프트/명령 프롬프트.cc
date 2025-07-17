#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, length;
    cin >> n;
    
    string file_name[n];
    for (int i = 0; i < n; i++) {
        cin >> file_name[i];
    }  
    
    int file_length = file_name[0].length();

    bool letter_bool[file_length];
    for (int i = 0; i < file_length; i++) {
        letter_bool[i] = 1;
    }
    for (int i = 0; i < file_length; i++) {
        for (int j = 0; j < n-1; j++) {
            if (file_name[j][i] != file_name[j+1][i]) {
                letter_bool[i] = false;
                break;
            }
        }
    }

    for (int i = 0; i < file_length; i++) {
        if (letter_bool[i] == 1) {
            cout << file_name[0][i];
        } else {
            cout << "?";
        }
    }
}