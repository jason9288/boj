#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string command;
    int queue[10001];
    int size = 0;
    int rear = 0;
    int front = 1;


    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "push") {
            int val;
            cin >> val;
            rear = (rear+1) % 10001;
            queue[rear] = val;
            size++;
        }
        else if (command == "pop") {
            if (size == 0) {
                cout << -1 << endl;
            } else {
                cout << queue[front] << endl;
                front = (front+1) % 10001;
                size--;
            }
        }
        else if (command == "size") {
            cout << size << endl;
        }
        else if (command == "empty") {
            cout << ((size == 0) ? 1 : 0) << endl;
        }
        else if (command == "front") {
            if (size == 0) {
                cout << -1 << endl;
            } else {
                cout << queue[front] << endl;
            }
        }
        else if (command == "back") {
            if (size == 0) {
                cout << -1 << endl;
            } else {
                cout << queue[rear] << endl;
            }
        }
        else {
            return 0;
        }

    }
}