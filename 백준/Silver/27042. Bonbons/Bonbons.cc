#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    while (q.size() > 1) {
        q.push(q.front());
        q.pop();
        q.pop();
    }

    cout << q.front();
}