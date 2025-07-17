#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<string, pair<float, float>>> table;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int cnt, n;
    cin >> n;
    cnt = n;

    while (cnt--) {
        string name;
        float a, b;
        cin >> name >> a >> b;
        table.push_back({name, {a, b}});
    }

    float best = 1e9;
    vector<string> best_team;

    for (int i = 0; i < n; i++) {
        string first = table[i].first;
        float first_time = table[i].second.first;

        vector<pair<string, float>> others;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                others.push_back({table[j].first, table[j].second.second});
            }
        }
        sort(others.begin(), others.end(), [](const pair<string, float> &a, const pair<string, float> &b) {
            return a.second < b.second;
        });

        float tot = first_time;
        vector<string> team = {first};
        for (int k = 0; k < 3; k++) {
            tot += others[k].second;
            team.push_back(others[k].first);
        }

        if (tot < best) {
            best = tot;
            best_team = team;
        }
    }

    cout << best << endl;
    for (const string &name : best_team) {
        cout << name << endl;
    }
}