#include <iostream>
using namespace std;

void print_star(int size, int depth) {
    for (int i = 0; i < size-depth; i++) {
        cout << " ";
    }
    for (int i = 0; i < depth; i++) {
        cout << "*";
    }
    cout << endl;
}

void recursion(int size, int depth) {
    if (size == depth) {
        for (int i = 0; i < size; i++) {
            cout << "*";
        }
        cout << endl;
    } else {
        depth += 1;

        print_star(size, depth-1);

        recursion(size, depth);

        print_star(size, depth-1);
    }
}

int main() {
    int a;
    cin >> a;

    recursion(a, 1);
}