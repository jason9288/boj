#include <iostream>
#include <vector>
using namespace std;

int ans = ~0U >> 2;
vector<pair<int, int>> shops;
vector<pair<int, int>> houses;

int cal_dist(pair<int,int> p1, pair<int, int> p2) {
    return (abs(p1.first - p2.first) + abs(p1.second - p2.second));
}

// cal city distance for a shop-house set
int city_dist(vector<pair<int, int>> shops, vector<pair<int, int>> houses) {
    int tot_dist = 0;
    int tempj;
    for (int i = 0; i < houses.size(); i++) {
        int dist = ~0U >> 2;
        for (int j = 0; j < shops.size(); j++) {
            int d = cal_dist(shops[j], houses[i]);
            if (d < dist) {
                dist = d;
                tempj = j;
            }
        }
        // printf("집 (%d, %d) 에서 가장 가까운 가게는 (%d, %d), 거리 %d\n",  houses[i].first, houses[i].second, shops[tempj].first, shops[tempj].second, dist);
        tot_dist += dist;
    }
    return tot_dist;
}

vector<pair<int, int>> get_combi_vec(vector<int> select, vector<pair<int, int>> map, int size) {
    vector<pair<int, int>> new_combi;
    for (int i = 0; i < size; i++) {
        if (select[i] == 1) {
            new_combi.push_back(map[i]);
        }
    }
    // cout << "현재 조합 : ";
    // for (int i = 0; i < new_combi.size(); i++) {
    //     printf("(%d, %d), ", new_combi[i].first, new_combi[i].second);
    // }
    // cout << endl;
    return new_combi;
}

void combi(vector<int>& select, vector<pair<int, int>>& map, int idx, int cnt, int n, int k) {
    if (cnt == k) {
        int city_d = city_dist(get_combi_vec(select, map, n), houses);
        if (city_d < ans) {
            ans = city_d;
        }
    }
    for (int i = idx; i < n; i++) {
        if (select[i] == 1) continue;
        select[i] = 1;
        combi(select, map, i, cnt+1, n, k);
        select[i] = 0;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int shop_cnt = 0;
    int house_cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            if (input == 1) {
                houses.push_back(make_pair(i, j));
                house_cnt++;
            }
            if (input == 2) {
                shops.push_back(make_pair(i, j));
                shop_cnt++;
            }
        }
    }

    // cout << endl;
    // cout << "shops: ";
    // for (int i = 0; i < shops.size(); i++) {
    //     printf("(%d, %d), ", shops[i].first, shops[i].second);
    // }
    // cout << endl;
    // cout << "houses: ";
    // for (int i = 0; i < houses.size(); i++) {
    //     printf("(%d, %d), ", houses[i].first, houses[i].second);
    // }

    vector<int> select(shops.size()+1, 0);
    // M개를 뽑는 모든 조합에 대해 최소 도시 비용 계산
    if (shops.size() <= m) {
        ans = city_dist(shops, houses);
    } else {
        combi(select, shops, 0, 0, shops.size(), m);
    }
    cout <<  ans;
}  