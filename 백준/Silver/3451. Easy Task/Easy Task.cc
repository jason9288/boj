#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<char, pair<int, int>> problem_submission_count; // {총 제출 수, 총 시간}
    unordered_map<char, int> problem_accepted_count;
    unordered_map<string, unordered_map<char, pair<bool, int>>> team_stats; // {solved, attempts}

    for (int i = 0; i < n; ++i) {
        int time;
        string team;
        char prob;
        char acc;
        cin >> time >> team >> prob >> acc;

        if (!team_stats[team][prob].first) { 
            team_stats[team][prob].second++; 
            
            if (acc == 'A') {
                team_stats[team][prob].first = true; 
                problem_accepted_count[prob]++;
                problem_submission_count[prob].second += time;
                problem_submission_count[prob].first += team_stats[team][prob].second; 
            }
        }
    }

    for (char prob = 'A'; prob <= 'I'; ++prob) {
        cout << prob << " ";

        if (problem_accepted_count[prob] == 0) {
            cout << "0" << endl;
        } else {
            double avg_submissions = (double)problem_submission_count[prob].first / problem_accepted_count[prob];
            double avg_time = (double)problem_submission_count[prob].second / problem_accepted_count[prob];
            cout << problem_accepted_count[prob] << " ";
            cout << fixed << setprecision(2) << avg_submissions << " ";
            cout << fixed << setprecision(2) << avg_time << endl;
        }
    }

    return 0;
}
