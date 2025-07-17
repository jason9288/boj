#include <iostream>
using namespace std;

void printa(int size, int depth);
void print_star(int size, int depth);

int main(void) {
    int a;
    cin >> a;
    printa(a, 1);
    return 0;
}

void print_star(int size, int depth) {
    for (int i = 0; i < depth; i++) {
        cout << "*";
    }

    for (int i = 0; i < 2*size - 2*depth; i++) {
        cout << " ";
    }

    for (int i = 0; i < depth; i++) {
        cout << "*";
    }
    printf("\n");
}

void printa(int size, int depth) {
    if (depth == size) {
        for (int i = 0; i < 2*size; i++) {
            cout << "*";
        }
        cout << endl;
    } else {
        depth += 1;

        print_star(size, depth-1);

        printa(size, depth);

        print_star(size, depth-1);
    }
}

