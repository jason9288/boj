#include <iostream>
#include <vector>
using namespace std;

int ans = -1;
int food[21];
int n, k;

void dfs(int depth, int sum, int energy, bool ate) {
    if (depth == n) {
        int last_e = sum >= k ? sum - k : 0;
        if (energy + last_e > ans) {
            ans = energy + last_e;
        }
        return;
    }
    int cur_food = food[depth];
    // 이전에 먹은 후 조건 만족 시 
    if (sum >= k) {
        // 이번 먹이 먹기
        dfs(depth+1, cur_food, energy+sum-k, 1);
        // 안 먹기
        dfs(depth+1, 0, energy+sum-k, 0);
    } else {
        if (ate) {
            dfs(depth+1, sum+cur_food, energy, 1);
        } else {
            dfs(depth+1, sum+cur_food, energy, 1);
            dfs(depth+1, sum, energy, 0);
        }
    }
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> food[i];
    }

    dfs(0, 0, 0, 0);
    cout << ans;
}